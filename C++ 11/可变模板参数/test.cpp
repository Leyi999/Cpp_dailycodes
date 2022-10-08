#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<class T>
void __print( T&& t) {//编译时决定 
	std::cout << typeid(t).name() << ' ' << t << endl;
}
template<class ...T>
void print(T... args) {
	/*if (!sizeof...(args))
		return 0;*///不能这样写，会报错 可变模板参数展开必须在编译时就决定好
	auto rl = { (__print(args),0)... };
	//等价于 
	/*initializer_list<int >il= {(__print(args), 0)...};*/
	cout << typeid(rl).name();//利用C++ 11 initializer_list的特性依次获取参数包
}
int main() {
	print("123", "321", 0.123,999);
	return 0;
}