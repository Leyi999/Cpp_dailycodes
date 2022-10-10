#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"smartptr.h"
using namespace std;
template<class T>
class SmartPtr {
public:
	//RAII 思想
	//把资源托管给对象，利用对象的声明周期管理释放资源
	SmartPtr(const T* ptr)
		:_ptr(ptr) {
		;
	}
	~SmartPtr() { delete _ptr;/*这里不用判空，delete会检查 如果是空就不释放 也不报错不抛异常*/ }
	SmartPtr(SmartPtr<T>& sp) =delete;
	SmartPtr<T>& operator=(SmartPtr<T>& sp) = delete;
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
private:
	T* _ptr;
};
// 这样实现有两个问题
//
//1.拷贝问题 
//不写默认的拷贝构造是值拷贝
//静态解决不了
// 所有类对象共享一个指针
//引用也解决不了
// 要更改指向的位置
//2.delete[] 还是 delete ，重不重载[] 
// 
// 
//库里面如何解决 拷贝问题
//C++ 98 std:: auto_ptr  
	/*SmartPtr(SmartPtr<T>& sp) 
	:_ptr(sp._ptr){sp._ptr = nullptr;}*/
// 管理权转移，被拷贝的对象被悬空 一解引用就出错  有隐患 考验程序员的功底 
//  很多公司要求不能使用
//boost 标准委员会成员写的第三方库 是C++标准库的后备 标准库会把里面精华部分拿到标准库里 还在更新
//boost  scoped_ptr shared_ptr weak_ptr 
//C++ 11 unique_ptr shared_ptr weak_ptr
//
////////////////////////////////////////////////////////       
// scoped_ptr -> c++11 unique_ptr  
//       特点：不允许拷贝 简单粗暴 你拷贝可能出问题 我就不让你拷贝
//int main() {
//	unique_ptr<int> sp1(new int);	   //实现方式一 :只声明 不实现
//	*sp1 = 1;						   //  C++98
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
// 方案二： 存一个静态的map<地址，count>//自创
// 方案三： 添加一个 int *pcount 构造的时候new一个count 析构的时候--(*pcount)
//
template<class T>
unordered_map<T*, int>s_m_SmartPtr<T>::_umap;
int main() {
	//方案三调式后未发现问题
	//s_SmartPtr<int>sp1(new int);
	//s_SmartPtr<int >sp2(sp1);
	//s_SmartPtr<int>sp3(new int);
	//sp2 = sp3;
	//return 0;
	//方案二调试后没问题
	s_m_SmartPtr<int>sp1(new int);
	s_m_SmartPtr<int >sp2(sp1);
	s_m_SmartPtr<int>sp3(new int);
	sp2 = sp3;
	return 0;
}