#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using std::cin;
using std::cout;
class Date {
public:
	//构造函数（全缺省）
	Date(int year = 2022, int month = 5, int day = 20);
	//拷贝构造
	Date(const Date& d);
	//析构
	~Date() {};
	//打印年月日
	void print() const{
		cout << _year << '.' << _month << '.' << _day << std::endl;
	}
	//判断日期是否合法
	bool IsLegalDate(const int year,const int month,const int day)const;
	//是否是闰年
	bool IsLeapYear(const int year) const{
		return (!(year % 4) && year % 100) || !(year % 400);
	}
	//返回月份的天数
	int GetMonthDay(const int year, const int month)const;
	//运算符重载：
	//+
	Date operator+(const int day)const;
	//-
	Date operator-(const int day)const;
	//+=
	Date& operator+=(const int day);
	//-=
	Date& operator-=(const int day);
	//前置++
	Date& operator++() {
		return *this += 1;
	}
	//后置++
	//后置++其实是前置++的重载函数，参数只用于区分，并不使用
	Date operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp ;
	}
	//前置--
	Date& operator--() {
		return *this -= 1;
	}
	//后置--
	//参数用于区分重载
	Date operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}
	//日期类-日期类返回间隔的天数(与日期减天数构成函数重载)
	int operator-(Date const& d)const;
	//=
	//赋值运算符 根据原赋值运算符的规则，返回引用
	Date& operator=(Date const& d);
	//关系运算符 年月日依次比较
	bool operator<(const Date& d)const;

	bool operator==(const Date& d)const;
	
	bool operator>(const Date& d)const;
	
	bool operator<=(const Date& d)const {
		return *this == d || *this < d;
	}
	bool operator>=(const Date& d)const {
		return *this == d || *this > d;
	}
	bool operator!=(const Date& d)const {
		return !(*this == d);
	}
	//取反重载为 将日期的真实性颠倒
	bool operator!()const {
		return !IsLegalDate(_year, _month, _day);
	}
private:
	int _year;
	int _month;
	int _day;
};
