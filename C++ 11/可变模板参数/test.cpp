#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
template<class T>
void __print(const T& t) {//编译时决定 
	std::cout << t << ' ';
}
template<class ...T>
void print(T... args) {
	/*if (!sizeof...(args))
		return 0;*///不能这样写，会报错 可变模板参数展开必须在编译时就决定好
	int arr[] = { (__print(args),0)... };
}
int main() {
	print("123", "321", 123);
	return 0;
}