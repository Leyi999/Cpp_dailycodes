#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class heap_only
{
	heap_only* get_obj(int n) {
		return new heap_only{ n };
	}
private:
	//heap_only& operator=(const heap_only& obj) = delete;
	heap_only(const heap_only& obj) = delete;
	heap_only(int n) :data(n){
	}
	int data;
};
class stack_only//这个没办法防止静态区
{
	//构造私有 就无法在外面new 子类也不能调用
	//静态成员可以直接通过类名访问
	//了解值传递 与声明周期
	static stack_only create_obj(int n) {
		return stack_only(n);
	}
private:
	//方法二
	//这两个的参数和返回值是固定的！
	//void* operator new(size_t size) { ; }
	//void  operator delete(void* p) { ; }
	stack_only(int n) :data(n) { ; }
	int data;
};
//不能被拷贝的类
//  =delete =default只有不写会默认生成的成员函数才能用
//拷贝构造=delete
// 	heap_only(const heap_only& obj) = delete;
//不能赋值的类
//  heap_only& operator=(const heap_only& obj) = delete;
//不能被继承的类
// c++98 构造私有
//c ++ 11 关键字final
class final_class final {
	;
};
//单例模式 
//饿汉模式
//一开始就创建 不管你用不用 简单省事儿
//缺点是 如果有多个单列 定义在不同.c文件中 无法控制初始化顺序 如果一例恰好依赖另一例就崩了
class hungry_man {
public:
	hungry_man& get_instance(){
		return obj;
	}
	hungry_man& operator=(const hungry_man& obj) = delete;
	hungry_man (const hungry_man& obj) = delete;

private:
	//构造为私有
	hungry_man() = default;
	//这里obj只是受到类域与访问限定符限定，而不是存在类里
	//加了static他是类的成员 也被视为是类的对象 可以访问私有
	static hungry_man obj;
};
//cpp全局中显示实例化
hungry_man hungry_man::obj;
//懒汉模式
class lazy_man {
public:
	static lazy_man& get_instance() {
		//用才 初始化
		if (!pobj)
			pobj = new lazy_man;
		return *pobj;
	}
	lazy_man& operator=(const lazy_man& obj) = delete;
	lazy_man(const lazy_man& obj) = delete;
	//因为单例在堆上 无法自动析构 定义一个回收类
	struct delete_class {
		~delete_class() {
			//内部类是外部类的友元 能访问pobj
			delete pobj;
		}
	};
private:
	//构造为私有
	lazy_man() = default;
	//因为无法构造所以需要静态
	static lazy_man* pobj;
};
lazy_man* lazy_man::pobj{nullptr};
lazy_man::delete_class dc;//程序结束后释放资源
int main() {
	lazy_man::get_instance();
	return 0;
}