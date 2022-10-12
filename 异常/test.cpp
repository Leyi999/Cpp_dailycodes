#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//优点：相比错误码，能抛出自定义类型有更多的错误信息，能帮助更好的定位程序的bug
//		相比错误码，深层的函数出错不用层层返回错误码，能直接跳到最近的catch
//		某些返回引用的函数 或者 构造函数等 无法很好的返回错误码
//		支持多态和继承 实现了方便地特殊处理某些特定错误
// 
// 
//缺点：导致程序乱跳，执行逻辑杂乱
//		有性能损耗（多数情况可忽略不计）
//
//C++独有的缺点：
//		没有垃圾回收器，很容易内存泄漏，需要用智能指针解决但学习成本较高
//		官方库关于异常的对象不够好用，满足不了需求，导致各公司都有自己实现，代码不那么规范统一

using namespace std;
int* getarr(size_t n)throw(std::exception) {//C++98 期望函数声明可能抛出的异常类型
	return new int[n] {0};
}
void print(const char* str)noexcept {//C++11 简化了期望 声明如果不抛出异常 
	cout << str;
}
int main() {
	try {//可能抛出异常的语句
		 //try 和 throw 不能省略{}
		
		int* tmp = getarr(10);
		try {//为了防止下面这段代码抛异常导致 tmp内存泄漏
			//主动try catch 处理一下
			int* arr = getarr(1000000000000);
			for (int i = 0; i < 10; i++)
				cout << arr[i];
		}
		catch (exception e) {
			delete[] tmp;
			throw e;//外抛异常 对于内存泄漏需要非常小心
		}
		//如果上面抛异常了 这条语句便不会执行
		delete[] tmp;
	}
	//一般抛出派生类对象 用父类捕获 用重写的函数获取错误信息
	//一般公司项目开发都会自己写用于异常捕获的基类，因为官方库里的满足不了需求，如 无法查看堆栈相关信息等。
	catch (exception e/*切片*/) {
		//throw能抛出任何类型，类似于函数值返回，抛出的是一个匿名右值对象
		//跟随调用堆栈找并跳到最近的catch复合语句
		//如果找不到catch会直接终止程序
		cout <<__LINE__<<"::" << "   " << e.what() /*多态重写*/ << endl;
	}
	catch(...){
		cout<<"未知异常";
	}
		
	return 0;
}