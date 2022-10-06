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
	Date d = { { 2022,10,6} };
			//先是多参数的隐式转换 构造一个date临时对象放入initializer_list中
			//然后用initializer_list<date> 构造d
	cout << d._year << ' ' << d._month << ' ' << d._day << endl;
	return 0;
}