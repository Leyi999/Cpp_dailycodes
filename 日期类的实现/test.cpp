#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date {
public:
	//���캯����ȫȱʡ��
	Date(int year = 2022, int month = 5, int day = 20) {
		CheckDate(year, month, day);//���
		_year = year;
		_month = month;
		_day = day;
	}
	//��������
	Date(Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//����
	~Date() {

	}
	//��ӡ������
	void print() {
		cout << _year << '.' << _month << '.' << _day<<endl;
	}
	//�ж������Ƿ�Ϸ�
	bool IsLegalDate(int year, int month, int day) {
		if (year <= 0 || (month <= 0 && month>12) || (day<=0 || day>GetMonthDay(year, month)))
			return false;
		return true;
	}
	//�Ƿ�������
	bool IsLeapYear(int year) {
		return (!(year % 4) && year % 100)|| !(year % 400);
	}
	//�����·ݵ�����
	int GetMonthDay(int year, int month) {
		int MonthDayArray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (IsLeapYear(year))
			MonthDayArray[1]++;
		return MonthDayArray[month-1];
	}
	//��������أ�
	//+
	Date operator+(int day) {
		Date tmp(*this);
		tmp._day += day;//������
		for (int monthday = GetMonthDay(tmp._year, tmp._month); tmp._day > monthday; monthday = GetMonthDay(tmp._year, tmp._month)) {//����
			tmp._day -= monthday;
			tmp._month++;
			if (tmp._month > 12) {
				tmp._month = 1;
				tmp._year++;
			}
		}
		CheckDate(tmp._year,tmp._month,tmp._day);//���
		return tmp;
	}
	//-
	Date operator-(int day) {
		Date tmp(*this);
		tmp._day -= day;//������
		for (int monthday = GetMonthDay(tmp._year, tmp._month); tmp._day <= 0; monthday = GetMonthDay(tmp._year, tmp._month)) {//����
			tmp._day += monthday;
			tmp._month--;
			if (tmp._month <= 0) {
				tmp._month = 12;
				tmp._year--;
				if (tmp._year <= 0) {//���
					cout << "�Ƿ����ڣ�" << endl;
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
	//����++
	Date operator++() {
		return *this+=1;
	}
	//ǰ��++
	//ǰ��++��ʵ�Ǻ���++�����غ���������ֻ�������֣�����ʹ��
	Date& operator++(int) {
		return *this += 1;
	}
	//����--
	Date operator--() {
		return *this -= 1;
	}
	//ǰ��--
	//����������������
	Date& operator--(int) {
		return *this -= 1;
	}
	//������-�����෵�ؼ��������
	int operator-(Date const& d) {
		int dev=0;
		if (_year > d._year)//�Ȱ���ݵ�����һ��
			for (int y = d._year; y != _year; y++)
				dev += IsLeapYear(y) ? 366 : 365;
		else
			for (int y = _year; y != d._year; y++)
				dev -= IsLeapYear(y) ? 366 : 365;
		//�ٰ��·�����һ��
		if (_month > d._month) 
			for (int m =d._month; m != _month; m++) 
				dev += GetMonthDay(d._year, m);
		else 
			for (int m = _month; m != d._month; m++) 
				dev -= GetMonthDay(d._year, m);
		//��
		dev += _day - d._day;
		return dev;
	}
	//=
	//��ֵ����� ����ԭ��ֵ������Ĺ��򣬷�������
	Date& operator=(Date const &d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//��ϵ����� ���������αȽ�
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
	//ȡ������Ϊ �����ڵ���ʵ�Եߵ�
	bool operator!() {
		return !IsLegalDate(_year, _month, _day);
	}
private:
	void CheckDate(int year,int month,int day) {
		if (!IsLegalDate(year, month, day)) {
			cout << "�Ƿ����ڣ�" << endl;
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