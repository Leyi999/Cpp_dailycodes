#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<initializer_list>
using namespace std;
class Date {
public:
	/* ������explicit �Ͳ�֧��������ʽ����ת����*/ Date(int year, int month, int day)
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
	A a = 1;//��1 ����A�Ĺ��캯������һ����ʱ����
			//������ʱ����ȥ��ֵ����
			//����ǵ���������ʽ����ת��,����A�Ĺ���ֻ��һ���βε��ص� ��1ת��ΪA
	//C++ 11
	Date b = { 2022,10,6 };//�� Data d{2022,10,6};
			//C++ 11֧���˶��������ʽ����ת�� 
			//����û��initializer_list�Ĺ��캯������Ҳ����
			//���������ƥ���ϵĲ���Ϊinitial_list�Ĺ����硰Date(initializer_list<int����double>il)��
			// �㲻����ʽת����ת���������еġ�
	Date d = { { 2022,10,6} };
			//���Ƕ��������ʽת�� ����һ��date��ʱ�������initializer_list��
			//Ȼ����initializer_list<date> ����d
	cout << d._year << ' ' << d._month << ' ' << d._day << endl;
	return 0;
}