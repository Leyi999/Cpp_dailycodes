#include"Date.h"
//���캯��
Date::Date(const int year ,const int month ,const int day ) {
	if (!IsLegalDate(year, month, day)) {
		cout << "�Ƿ����ڣ�" << std::endl;
		exit(1);
	}//���
	_year = year;
	_month = month;
	_day = day;
}
//��������
Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
//�ƶ����� , �ƶ���ֵ ������������ ����Ҫʵ�� 
//�ж������Ƿ�Ϸ�
bool Date::IsLegalDate(const int year, const int month, const int day)const {
	if (year <= 0 || (month <= 0 && month > 12) || (day <= 0 || day > GetMonthDay(year, month)))
		return false;
	return true;
}
//�����·�����
int Date::GetMonthDay(const int year, const int month)const {
	static int MonthDayArray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return MonthDayArray[month - 1] + (month == 2 && IsLeapYear(year) ? 1 : 0);
}
//+= ����
Date& Date:: operator+=(const int day) {
	_day += day;//������
	for (int monthday = GetMonthDay(_year, _month); _day > monthday; monthday = GetMonthDay(_year, _month)) {//����
		_day -= monthday;
		_month++;
		if (_month > 12) {
			_month = 1;
			_year++;
		}
	}
	return *this;
}
//+ ����
Date Date::operator+(const int day) const {
	Date tmp(*this);
	return tmp += day;
}


//-=����
Date& Date::operator-=(const int day) {
	_day -= day;//������
	while (_day <= 0) {//����
		_month--;
		if (_month <= 0) {
			_month = 12;
			_year--;
			if (_year <= 0) {//���
				cout << "�Ƿ����ڣ�" << std::endl;
				exit(1);
			}
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
//- ����
Date Date::operator-(const int day)const
{
	Date tmp(*this);
	return tmp-=day;
}
//������-�����෵�ؼ��������(�����ڼ��������ɺ�������)
int Date::operator-(Date const& d)const {
	int dev = 0;
	if (_year > d._year)//�������
		for (int y = d._year; y != _year; y++)
			dev += IsLeapYear(y) ? 366 : 365;
	else
		for (int y = _year; y != d._year; y++)
			dev -= IsLeapYear(y) ? 366 : 365;
	//�²�
	if (_month > d._month)
		for (int m = d._month; m != _month; m++)
			dev += GetMonthDay(d._year, m);
	else
		for (int m = _month; m != d._month; m++)
			dev -= GetMonthDay(d._year, m);
	//�ղ�
	dev += _day - d._day;
	return dev;
}
//��ֵ����� ����ԭ��ֵ������Ĺ��򣬷�������
Date& Date::operator=(Date const& d) {
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//��ϵ����� ���������αȽ�
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