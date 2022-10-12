#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct A {
	virtual void f() {
		cout << "f" << endl;
	}
};
struct B :public A {
	//void f() {
	//	cout << "s"<<endl;
	//}
};
void print(A* ptr) {
	//(B*)ptr 这样写会无论怎样都报错
	//reinterpret_cast<B*>(ptr)//这样写可以但是不会检查安全性
	if (dynamic_cast<B*>(ptr))//必须要求父类里有虚函数 但不要求子类重写
		cout << "安全，转换成功" << endl;
	else
		cout << "不安全，无法转换，动态转换返回空 "<<endl;//说明原本是指向父的指针 如转成子类的 就多看了 那是不安全的
}
int main() {
	//C的类型转换 

	//隐式类型转换->相近意义的类型转换
	size_t a = 0;
	int b = 1;
	a = b;
	//强制类型转换（显示的）-> 意义不将近的
	int* p = (int*)a;

	//C++希望代码更加规范 但又要兼容C 所以并没有强制要求放弃C的方式，大家也没有普遍使用C++更规范的类型转换语法，但有一些公司是要求的。
	//将类型转换 分为四种 static_cast  reinterpret_cast const_cast dynamic_cast
	// 用法 ..._cast<要转成的类型>（表达式）;
	// static:对应C的隐式类型转换
	// reinterpret:对应C中 意义不相似类型间的强转
	// const 用于C中把const去掉的强转
	volatile const int c = 1;
	//int* pc = (int*)&c;
	int* pc = const_cast<int*>(&c);
	*pc = 2;
	cout << c<<endl;
	//         补充 ：如果不用volatile 打印出来就1 因为编译器认为你不会修改const变量 所有就没有从内存去取可能直接从常量区去取了 或者把1放在寄存器 要打印直接从寄存器取
	//                如果加了volatile 便要求 必须去内存中取 打印出来就是2。
	//  dynamic_cast(C++独有): 若能安全向下转换返回转换后的值，若不能返回0;
	// 要求 1: 原本指向子的指针（安全）
	// 要求 2：有重写的虚函数
	// 应用场景:
	A f;
	B s;
	print(&f);
	print(&s);
	//如何 在函数print里知道 ptr是本来就指向父类还是 由子类切片而成？
	//见第15行

	  
	return 0;
}