#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"smartptr.h"
using namespace std;
template<class T>
//C++ 没有垃圾回收器 容易内存泄漏
//1.忘记释放
//2.delete之前抛异常跳过释放语句 
//试用RAII思想 解决
//RAII:
//把资源托管给对象，利用对象的声明周期管理释放资源,构造时获得资源，析构时释放资源。
//RAII 思想为智能指针的指导思想，并不等于智能指针
//RAII 还可以用于 管理锁 等很多两步操作 如 锁 -> 解锁， 申请资源 -> 释放资源， 开->关。
//智能指针 ：
//			1.RAII思想 利用声明周期管理释放资源
//			2.能像指针一样使用
//试试自己实现一个 RAII思想的智能指针
class SmartPtr {
public:
	//RAII 思想
	//把资源托管给对象，利用对象的声明周期管理释放资源,构造时获得资源，析构时释放资源。
	SmartPtr(const T* ptr)
		:_ptr(ptr) {
		;
	}
	~SmartPtr() { delete _ptr;/*这里不用判空，delete会检查 如果是空就不释放 也不报错不抛异常*/ }
	//像指针一样使用
	SmartPtr(SmartPtr<T>& sp) =delete;
	SmartPtr<T>& operator=(SmartPtr<T>& sp) = delete;
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
private:
	T* _ptr;
};
//这样实现有两个问题 拷贝问题  以及 delete 还 delete[] -> 定制删除器（仿函数解决，默认用delete）参考smartptr.h 
//					|
//				出现拷贝问题：拷贝后谁管理资源？
//				C++ 98 auto_ptr: 管理权转移，将被拷贝对象置空，一解引用就出错  有隐患 考验程序员的功底 ->很多公司明确要求不允许使用auto_ptr
//					|																	/*SmartPtr(SmartPtr<T>& sp) 
//					|																		:_ptr(sp._ptr) { sp._ptr = nullptr; }*/
//				boost库                   scoped_ptr  shared_ptr  weak_ptr...	->  boost 为 有标准委员会成员参与写的第三方库 是C++标准库的后备（准标准库）标准库会把里面精华部分拿到标准库里 还在更新
//				C++ 11 标准库<memory>	  unique_ptr  shared_ptr  weak_ptr		->	boost库中提取精华并加以改进后引入 
//					|
//					|				
////////////////////////////////////////////////////////       
// scoped_ptr -> c++11 unique_ptr  
//       特点：不允许拷贝 简单粗暴 你拷贝可能出问题 我就不让你拷贝
//int main() {
//	unique_ptr<int> sp1(new int);	   //实现方式一 :只声明 不实现
//	*sp1 = 1;						   //  C++98 （boost）
////unique_ptr<int> sp2(sp1);编译不通过//  1.只声明 不实现 让你编译不通过
//	SmartPtr<int>msp1(new int);		   // SmartPtr(SmartPtr<T>&sp);   
//	SmartPtr<int>msp2(msp1);		   //  但是害怕被别人实现
//									   //  2.声明成私有
//									   //  C++11
//									   // SmartPtr(SmartPtr<T>&sp) = delete;别人就调不了了   
//	return 0;						   //SmartPtr<T>& operator=(SmartPtr<T>& sp) = delete;
//}
//////////////////////////////////////////////////////////
// 但是总会有需要拷贝的场景--> shared_ptr
// 核心原理：引用计数 析构的时候--计数 最后一个析构的对象释放资源
// //库里的实现非常复杂 考虑了很多问题 我们模拟实现有以下方案
// 方案一： 用一个静态的成员 static int count  构造时++ 析构时 --为0时释放
//			不可行原因： 所有成员共有不能做到一份资源 匹配一个count
// 方案二： 存一个静态的map<地址，count>//自创 可行，但是随着智能指针增多代价会变得难以接受，多线程下上锁代价更大，且如用hashmap，还不能随着智能指针减少释放资源
// 方案三： 添加一个 int *pcount 构造的时候new一个count 析构的时候--(*pcount) //最优
//template<class T>
//unordered_map<T*, int>s_m_SmartPtr<T>::_umap;//初始化静态成员
//int main() {
//	//方案三调式后未发现问题
//	//s_SmartPtr<int>sp1(new int);
//	//s_SmartPtr<int >sp2(sp1);
//	//s_SmartPtr<int>sp3(new int);
//	//sp2 = sp3;
//	//return 0;
//	//方案二调试后没问题
//	s_m_SmartPtr<int>sp1(new int);
//	s_m_SmartPtr<int >sp2(sp1);
//	s_m_SmartPtr<int>sp3(new int);
//	sp2 = sp3;
//	return 0;
//}
// 但是shared_ptr 有一个致命的问题 -> 循环引用!
// 试调试以下代码
// struct List {
//	shared_ptr<List> pev;
//	shared_ptr<List> next;
//	int x=0;
//};
//int main() {
//	shared_ptr<List> sp1(new List);
//	shared_ptr<List> sp2(new List);
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	//这里构成循环引用
//	sp1->next = sp2;
//	sp2->next = sp1;
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	return 0;//当声明周期结束时两个节点都不会释放
//			 //都是析构时都是减到1 ,因为彼此管理彼此依赖，但凡一个不管理另一个都两个节点都可以成功释放。
//}
////////////////////////////////////////////////////////////////////////////////////////
//  weak_ptr ->专门解决shared_ptr的循环引用问题
//  特点:  非RAII 能访问读写资源 但不参与管理释放！
//		   只提供无参的构造以及share_ptr的拷贝构造和赋值重载 模拟实现见smartptr.h
// 当使用shared_ptr时 不需要参与管理资源释放的指针改用weak_ptr！
// 试调使用weak_ptr后的代码 解决了shared_ptr 循环引用的问题
// struct List {
//	w_SmartPtr<List> pev;//用weak_ptr ，不参与资源释放管理
//	w_SmartPtr<List> next;
//};
//int main() {
//	s_SmartPtr<List> sp1(new List);
//	s_SmartPtr<List> sp2(new List);
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	//这里不构成构成循环引用 
//	sp1->next = sp2;
//	sp2->next = sp1;
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	return 0;//当声明周期结束时两个节点 按照 sp2 -> sp1 的顺序顺利析构
//}
// /////////////////////////////////
// 测试定制删除器
//template<class T>
//struct DeleteArr
//{
//	void operator()(T* arr) {
//		delete[]arr;
//	}
//};
//int main() {
//	u_SmartPtr<int,DeleteArr<int>>sp1(new int[10]{1,9,7,6,4,8,2,3,4,5});
//	for (int i = 0; i < 10; i++)
//		cout << sp1.get()[i] << ' ';
//	return 0;
//}
// 
///////////////////////////////////////////////////
// 库里shared_ptr 定制删除器的方法
int main() {
	int* ptr = static_cast<int*>(calloc(10, 4));
	shared_ptr<int>(ptr, [](int* p) {free(p); cout << "free"; });//传对象
	return 0;
}
// unique_ptr 跟我们实现的一样，实例化时传入仿函数类型 就不演示了
//