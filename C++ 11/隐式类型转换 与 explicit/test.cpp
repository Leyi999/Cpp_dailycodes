#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<initializer_list>
using namespace std;
class Date {
public:
	/* 若加上explicit 就不支持那种隐式构造转换了*/ Date(int year, int month, int day)
		:_year(year),_month(month),_day(day)
	{
		;
	}
	Date(initializer_list<Date>il)
		:_year(1), _month(2), _day(3)
	{
		;
	}
	Date(initializer_list<int>il)
		:_year(3), _month(2), _day(1)
	{
		;
	}
	Date(Date&& d)noexcept {
		swap(_year,d._year);
		swap(_month, d._month);
		swap(_day, d._day);
		cout << "拷贝构造";
	}
	operator bool() {
		if (_year)
			return true;
		return false;
	}
	operator int() {
		return _year + _month + _day;
	}
	int _year;
	int _month;
	int _day;
};
class A {
public:
	A(int a) {
		_a = a;
	}
	int _a;
};
int main() {
	//C++ 98
	A a = 1;//把1 借助A的构造函数构造一个临时对象
			//再用临时对象去赋值重载
			//这就是单参数的隐式类型转换,借助A的构造只有一个形参的特点 把1转换为A
	//C++ 11
	Date b = { 2022,10,6 };//或 Data d{2022,10,6};
			//C++ 11支持了多参数的隐式类型转换 
			//就算没有initializer_list的构造函数重载也可以
			//但如果有能匹配上的参数为initial_list的构造如“Date(initializer_list<int或者double>il)”
			// 便不会隐式转换，转而调用以有的。
			//il 优先 如果没有匹配的il构造就会隐式类型转换，但一般会被优化为直接构造
	Date d = { { 2022,10,6} };
			//先是多参数的隐式转换 构造一个date临时对象放入initializer_list中
			// 因为有il<int>，会用il<int>构造临时对象
			//然后用initializer_list<date> 构造d
	cout << d._year << ' ' << d._month << ' ' << d._day << endl;
	//基础补充
	double e = 1.0;
	int&& f = e;
	const int& g = e;
	/*E0434	无法用 "double" 类型的值初始化 "int &" 类型的引用(非常量限定)	
	int& h =e;*/
	            //任何类型转换都会生成临时变量
				//兼容c里 相似意义类型可以隐式转换的规则
				//这个临时变量是右值，具有常性
				//只能用 const& 或者 &&来引用
//////////////////////////////////////////////////////////////////////////////////////
	//自定义类型隐式转换为其他类型（包括内置类型）
	//要求重载类型转换运算符
	int x = d;//int
	if(d)//重载隐式类型转换为bool值
	printf("\n%d\n", x);
	return 0;
}