#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using std::cin;
using std::cout;
class Date {
public:
	//���캯����ȫȱʡ��
	Date(int year = 2022, int month = 5, int day = 20);
	//��������
	Date(const Date& d);
	//����
	~Date() {};
	//��ӡ������
	void print() const{
		cout << _year << '.' << _month << '.' << _day << std::endl;
	}
	//�ж������Ƿ�Ϸ�
	bool IsLegalDate(const int year,const int month,const int day)const;
	//�Ƿ�������
	bool IsLeapYear(const int year) const{
		return (!(year % 4) && year % 100) || !(year % 400);
	}
	//�����·ݵ�����
	int GetMonthDay(const int year, const int month)const;
	//��������أ�
	//+
	Date operator+(const int day)const;
	//-
	Date operator-(const int day)const;
	//+=
	Date& operator+=(const int day);
	//-=
	Date& operator-=(const int day);
	//ǰ��++
	Date& operator++() {
		return *this += 1;
	}
	//����++
	//����++��ʵ��ǰ��++�����غ���������ֻ�������֣�����ʹ��
	Date operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp ;
	}
	//ǰ��--
	Date& operator--() {
		return *this -= 1;
	}
	//����--
	//����������������
	Date operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}
	//������-�����෵�ؼ��������(�����ڼ��������ɺ�������)
	int operator-(Date const& d)const;
	//=
	//��ֵ����� ����ԭ��ֵ������Ĺ��򣬷�������
	Date& operator=(Date const& d);
	//��ϵ����� ���������αȽ�
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
	//ȡ������Ϊ �����ڵ���ʵ�Եߵ�
	bool operator!()const {
		return !IsLegalDate(_year, _month, _day);
	}
private:
	int _year;
	int _month;
	int _day;
};
