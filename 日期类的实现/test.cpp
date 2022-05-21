#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date {
public:
	//构造函数（全缺省）
	Date(int year = 2022, int month = 5, int day = 20) {
		CheckDate(year, month, day);//检查
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造
	Date(Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//析构
	~Date() {

	}
	//打印年月日
	void print() {
		cout << _year << '.' << _month << '.' << _day<<endl;
	}
	//判断日期是否合法
	bool IsLegalDate(int year, int month, int day) {
		if (year <= 0 || (month <= 0 && month>12) || (day<=0 || day>GetMonthDay(year, month)))
			return false;
		return true;
	}
	//是否是闰年
	bool IsLeapYear(int year) {
		return (!(year % 4) && year % 100)|| !(year % 400);
	}
	//返回月份的天数
	int GetMonthDay(int year, int month) {
		int MonthDayArray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (IsLeapYear(year))
			MonthDayArray[1]++;
		return MonthDayArray[month-1];
	}
	//运算符重载：
	//+
	Date operator+(int day) {
		Date tmp(*this);
		tmp._day += day;//加天数
		for (int monthday = GetMonthDay(tmp._year, tmp._month); tmp._day > monthday; monthday = GetMonthDay(tmp._year, tmp._month)) {//调整
			tmp._day -= monthday;
			tmp._month++;
			if (tmp._month > 12) {
				tmp._month = 1;
				tmp._year++;
			}
		}
		CheckDate(tmp._year,tmp._month,tmp._day);//检查
		return tmp;
	}
	//-
	Date operator-(int day) {
		Date tmp(*this);
		tmp._day -= day;//减天数
		for (int monthday = GetMonthDay(tmp._year, tmp._month); tmp._day <= 0; monthday = GetMonthDay(tmp._year, tmp._month)) {//调整
			tmp._day += monthday;
			tmp._month--;
			if (tmp._month <= 0) {
				tmp._month = 12;
				tmp._year--;
				if (tmp._year <= 0) {//检查
					cout << "非法日期！" << endl;
					exit(1);
				}
			}
		}
		return tmp;
	}
	//+=
	Date& operator+=(int day) {
		return *this = *this + day;
	}
	//-=
	Date& operator-=(int day) {
		return *this = *this - day;
	}
	//后置++
	Date operator++() {
		return *this+=1;
	}
	//前置++
	//前置++其实是后置++的重载函数，参数只用于区分，并不使用
	Date& operator++(int) {
		return *this += 1;
	}
	//后置--
	Date operator--() {
		return *this -= 1;
	}
	//前置--
	//参数用于区分重载
	Date& operator--(int) {
		return *this -= 1;
	}
	//日期类-日期类返回间隔的天数
	int operator-(Date const& d) {
		int dev=0;
		if (_year > d._year)//先把年份的拉到一样
			for (int y = d._year; y != _year; y++)
				dev += IsLeapYear(y) ? 366 : 365;
		else
			for (int y = _year; y != d._year; y++)
				dev -= IsLeapYear(y) ? 366 : 365;
		//再把月份拉到一样
		if (_month > d._month) 
			for (int m =d._month; m != _month; m++) 
				dev += GetMonthDay(d._year, m);
		else 
			for (int m = _month; m != d._month; m++) 
				dev -= GetMonthDay(d._year, m);
		//日
		dev += _day - d._day;
		return dev;
	}
	//=
	//赋值运算符 根据原赋值运算符的规则，返回引用
	Date& operator=(Date const &d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//关系运算符 年月日依次比较
	bool operator<(const Date& d) {
		return _year < d._year ? true : (_year == d._year ? (_month < d._month ? true : (_month == d._month ? (_day < d._day) : false)) : false);
	}
	bool operator==(const Date& d) {
		return d._year == _year && d._month == _month && d._day == _day;
	}
	bool operator>(const Date& d) {
		return _year > d._year ? true : (_year == d._year ? (_month > d._month ? true : (_month == d._month ? (_day > d._day) : false)) : false);
	}
	bool operator<=(const Date& d) {
		return *this == d || *this < d;
	}
	bool operator>=(const Date& d) {
		return *this == d || *this > d;
	}
	bool operator!=(const Date& d) {
		return !(*this == d);
	}
	//取反重载为 将日期的真实性颠倒
	bool operator!() {
		return !IsLegalDate(_year, _month, _day);
	}
private:
	void CheckDate(int year,int month,int day) {
		if (!IsLegalDate(year, month, day)) {
			cout << "非法日期！" << endl;
			exit(1);
		}
	}
	int _year;
	int _month;
	int _day;
};
int main() {
	int a = 1, b = 4;
	Date d2(1983, 5, 21), d1(2030, 1, 31);

	cout<<d1- d2;
	
	return 0;
}