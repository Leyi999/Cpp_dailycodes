#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	//lambda表达式 返回一个可调用的匿名对象，可以用auto 自动推导类型来接受，能在局部定义，与局部深度绑定
	//写法：    [捕获列表] (形参) mutable -> 返回类型{ 函数体 }  
	// 特殊的点在于它的捕获列表[]且方括号不可省略，能捕获父作域（也就是写表达式那行所在的作用域）的所有对象,便可以省去一部分形参实参的传递
	//									//不能捕获全局的！除非表达式的父域就是全局。
	//									//方括号里不写默认不捕获
	//									//=以值的方式捕获，
	//									//&以引用的方式捕获（左值）可修改会改变绑定对象
	//									//this指针 可以值的方式被lambda表达式捕获 （仅在类里使用lambda表达式时可用，可能{}里需要调用成员函数，=就可以，this只不过单独写出来了）
	//									//也可以混合捕获，如“=，&b”或“&，b”“&，a,this”的方式，非常灵活
	// 
	//(形参表) 可以在调用是传递实参，不需要定义形参时可以省略不写 
	// 形参表和捕获列表中的值捕获 默认都是加const的,可选择在括号后加mutable来去掉const，但也是实参的拷贝，改变不影响实参
	// 但加mutable就不能省略形参表的“()”，这个关键字只能加载在括号后面
	// 
	//->返回类型 可以选择省略，编译器能自动推导
	int a, b;
	a = 1;
	b = 2;
	cout << [=]/*()mutable */ {
		//a = 1;
		return a + b; } () << endl;//用lambda表达式返回一个可调用的匿名对象后 调用之
									//调用时不需要传参，因为匿名对象捕获了父作用域的所有对象（值捕获）
		
	//反汇编调试可以看到
	//每个lambda都会被转换成一个仿函数类型的对象
	//仿函数类型名称为lambda_uuid 编译器取名 是对程序员隐藏的
	//lambda表达式返回的就是用这个lambda_uuid类生成的匿名对象
	// 然后可以用()去调用这个匿名对象的operator() 
	auto/*class lambda_6228018fac939beb5ef053b0e01ccde4*/ int_less = 
		[=] {return a < b; };
	auto/*class lambda_7ac0f67ecf6141cc4212d74c5c56e6e1*/ int_greater =
		[=/* &或者&,a或者=,&a 或者  ... */]/*()->bool*/ {return a > b; };
	cout << typeid(int_less).name() << endl;
	//输出class <lambda_6228018fac939beb5ef053b0e01ccde4>
	int arr[] = { 1,5,7,9,4,6,8,2,3,0,10,49,31,65,821,666,999 };
	//使用场景
	//排升序
	//sort是函数模板能自动推导lambda表达式的类型
	/*struct Ls {
		bool operator()(int a, int b) {
			return a < b;
		}
	};*/
	sort(arr, arr + (sizeof(arr) / sizeof(arr[1])), /*Ls()*/[&](int a, int b)->bool {return a < b; });
	for (auto e : arr)
		cout << e << ' ';
	//补充 不推荐的用法
	//lambda表达式可以赋值给void类型无形参的函数指针 特殊处理的语法
	//原理是把operator()的地址给了这个指针
	//平时都不会用 因为函数指针本来就是被嫌弃的东西
	void(*pf)();
	pf = [] {cout <<endl<< "hello world!!!"<<endl; };
	pf();
	return 0;
}