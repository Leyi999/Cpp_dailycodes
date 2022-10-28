#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
#include<unordered_map>
#include<string>
using namespace std;
int add(int a, int b) {
	return a + b;
}
class puls {
	int pls(int a, int b) {
		return a + b;
	}
};
struct Add {
	int operator()(int a,int b){
		return a + b;
	}
};
class myclass {
public:
	static int sadd(int a, int b) {
		return a + b;
	}
	int cadd(int a, int b) {
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		return a + b;
	}
};
class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a + b;
	}
};

int main() {
	//包装 返回值形参一致的 不同类型或相同类型的 可调用对象
	//底层用可变模板参数实现 是类模板
	function<int(int, int)> f1 = add;
	function<int(int, int)>f2 = [](int a, int b) {return a + b; };
	function<int(int, int)>f3 = Add();
	//类成员中的函数包装
	//需要添加一个类的类型参数
	//本质上使用类生成类对象去调用 myclass 代表this指针(推测) 
	function<int(myclass, int, int)>f4 = &myclass::cadd;//类域前取地址是语法规定
	//类中静态成员函数包装时 不加类的类型参数，类域前也不需要取地址（取地址也可不报错）
	function<int(int, int)>f5 = /*&*/ myclass::sadd;

	//bind 函数模板
	//可以用bind函数来调整参数个数和循序  第一个参数为要包装的对象，后面可以给定要省略的参数，和调整顺序
	//placeholders是std里的命名空间 _1 _2代表本来的参数循序，可以_2 _1就交换了循序 
	//省略个数
	function<int(int, int)> f6 = bind(&myclass::cadd, myclass(),placeholders::_1,placeholders::_2);
	std::cout <<f6(1, 2)<<endl;
	//改变循序
	function<int(int, int)> f7 = bind(myclass::sadd, placeholders::_2, placeholders::_1);
	std::cout << f7(2, 1);

	//使用场景 
	//命令 对应 方法
	// 如oj题 逆波兰表达式求值
	// #include<stack>
	//#include<iostream>
	//#include<functional>
	//#include<unordered_map>
	//	using namespace std;
	//	class Solution {
	//	public:
	//		int evalRPN(vector<string>& tokens) {
	//			unordered_map<string, function<long long(long long, long long)>> umap;
	//			umap["+"] = [](long long a, long long b) {return a + b; };
	//			umap["-"] = [](long long a, long long b) {return a - b; };
	//			umap["*"] = [](long long a, long long b) {return a * b; };
	//			umap["/"] = [](long long a, long long b) {return a / b; };
	//			stack<long long> st1;
	//			for (auto& e : tokens) {
	//				if (e != "+" && e != "-" && e != "*" && e != "/") {
	//					st1.push(stoi(e));
	//				}
	//				else {
	//					long long b = st1.top();//先拿b在拿a 保证左右操作数正确
	//					st1.pop();
	//					long long a = st1.top();
	//					st1.pop();
	//					st1.push(umap[e](a, b));
	//				}
	//			}
	//			return st1.top();
	//		}
	//	};
	//
	unordered_map<string, function<int(int, int)>> opumap;
	opumap["函数指针"] = f1;
	opumap["lambda表达式"] = f2;
	opumap["仿函数"] = f3;
	opumap["类非静态成员函数"] = f6;
	opumap["改变形参顺序的静态成员函数"] = f7;
	//输入指令可调用方法 把不同方法包装成相同类型 放入哈希map或者红黑树map
	//这里代码只是提供思路 其实都是加法hh
	cout << endl << opumap["仿函数"](666, 333)<<endl;
	return 0;
}