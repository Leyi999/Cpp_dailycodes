#include"Date.h"
//构造函数
Date::Date(const int year ,const int month ,const int day ) {
	if (!IsLegalDate(year, month, day)) {
		cout << "非法日期！" << std::endl;
		exit(1);
	}//检查
	_year = year;
	_month = month;
	_day = day;
}
//拷贝构造
Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
//移动构造 , 移动赋值 都是内置类型 不需要实现 
//判断日期是否合法
bool Date::IsLegalDate(const int year, const int month, const int day)const {
	if (year <= 0 || (month <= 0 && month > 12) || (day <= 0 || day > GetMonthDay(year, month)))
		return false;
	return true;
}
//返回月份天数
int Date::GetMonthDay(const int year, const int month)const {
	static int MonthDayArray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return MonthDayArray[month - 1] + (month == 2 && IsLeapYear(year) ? 1 : 0);
}
//+= 天数
Date& Date:: operator+=(const int day) {
	_day += day;//加天数
	for (int monthday = GetMonthDay(_year, _month); _day > monthday; monthday = GetMonthDay(_year, _month)) {//调整
		_day -= monthday;
		_month++;
		if (_month > 12) {
			_month = 1;
			_year++;
		}
	}
	return *this;
}
//+ 天数
Date Date::operator+(const int day) const {
	Date tmp(*this);
	return tmp += day;
}


//-=天数
Date& Date::operator-=(const int day) {
	_day -= day;//减天数
	while (_day <= 0) {//调整
		_month--;
		if (_month <= 0) {
			_month = 12;
			_year--;
			if (_year <= 0) {//检查
				cout << "非法日期！" << std::endl;
				exit(1);
			}
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
//- 天数
Date Date::operator-(const int day)const
{
	Date tmp(*this);
	return tmp-=day;
}
//日期类-日期类返回间隔的天数(与日期减天数构成函数重载)
int Date::operator-(Date const& d)const {
	int dev = 0;
	if (_year > d._year)//计算年差
		for (int y = d._year; y != _year; y++)
			dev += IsLeapYear(y) ? 366 : 365;
	else
		for (int y = _year; y != d._year; y++)
			dev -= IsLeapYear(y) ? 366 : 365;
	//月差
	if (_month > d._month)
		for (int m = d._month; m != _month; m++)
			dev += GetMonthDay(d._year, m);
	else
		for (int m = _month; m != d._month; m++)
			dev -= GetMonthDay(d._year, m);
	//日差
	dev += _day - d._day;
	return dev;
}
//赋值运算符 根据原赋值运算符的规则，返回引用
Date& Date::operator=(Date const& d) {
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//关系运算符 年月日依次比较
bool Date::operator<(const Date& d) const{
	return _year < d._year ? true : (_year == d._year ? (_month < d._month ? true : (_month == d._month ? (_day < d._day) : false)) : false);
}
bool Date::operator==(const Date& d) const{
	return d._year == _year && d._month == _month && d._day == _day;
}
bool Date::operator>(const Date& d) const{
	return _year > d._year ? true : (_year == d._year ? (_month > d._month ? true : (_month == d._month ? (_day > d._day) : false)) : false);
}
std::ostream& operator <<(std::ostream& out, const Date& d){
	return out << d._year << ' ' << d._month << ' ' << d._day;
}
std::istream& operator >>(std::istream& in, Date& d) {
	return in >> d._year >> d._month >> d._day; 
}