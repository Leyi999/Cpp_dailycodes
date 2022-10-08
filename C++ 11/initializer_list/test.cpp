#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.hpp"

#include<iostream>//间接包含了<initializer_list>

using namespace mystl;
int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	auto al = { 1,2,3 };
	const vector<int>cv({ 1,2,3 });
	//const vector<int >cv={3,2,1};
	//单参数的构造 隐式类型转换
	//1.先调用cv的默认构造
	//2.先用{}构造一个initializer_list 匿名对象
	//3.再用这个调用vt的构造，构造一个vt匿名对象
	//  其实3就是隐式转换,将 initlist转换为vt
	//4.再调用vt的复制重载 cv=匿名vt
	//一般会被编译器优化为直接用 这个initlist去构造vt ，类似于2,cv的构造 ==> const vector<int>({3,2,1});//也就不用隐式转换
	//注意{} 构造initializer_list 这一点是标准以及编译器原生支持的
	for (auto e : cv) {
		std::cout << e << " ";
	}
	cout << endl;
	v = { 4,5,6 };

	//这里就是
	//调用构造 用initlist构造一个vt匿名对象 （隐式转换）
	//用赋值重载
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	//类似于
	string str = "123";
	str = "456";
	return 0;
}