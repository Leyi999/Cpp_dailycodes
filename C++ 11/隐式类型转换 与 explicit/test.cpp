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
	Date(initializer_list<int>il)
		:_year(3), _month(2), _day(1)
	{
		;
	}
	Date(Date&& d)noexcept {
		swap(_year,d._year);
		swap(_month, d._month);
		swap(_day, d._day);
		cout << "��������";
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
	A a = 1;//��1 ����A�Ĺ��캯������һ����ʱ����
			//������ʱ����ȥ��ֵ����
			//����ǵ���������ʽ����ת��,����A�Ĺ���ֻ��һ���βε��ص� ��1ת��ΪA
	//C++ 11
	Date b = { 2022,10,6 };//�� Data d{2022,10,6};
			//C++ 11֧���˶��������ʽ����ת�� 
			//����û��initializer_list�Ĺ��캯������Ҳ����
			//���������ƥ���ϵĲ���Ϊinitial_list�Ĺ����硰Date(initializer_list<int����double>il)��
			// �㲻����ʽת����ת���������еġ�
			//il ���� ���û��ƥ���il����ͻ���ʽ����ת������һ��ᱻ�Ż�Ϊֱ�ӹ���
	Date d = { { 2022,10,6} };
			//���Ƕ��������ʽת�� ����һ��date��ʱ�������initializer_list��
			// ��Ϊ��il<int>������il<int>������ʱ����
			//Ȼ����initializer_list<date> ����d
	cout << d._year << ' ' << d._month << ' ' << d._day << endl;
	//��������
	double e = 1.0;
	int&& f = e;
	const int& g = e;
	/*E0434	�޷��� "double" ���͵�ֵ��ʼ�� "int &" ���͵�����(�ǳ����޶�)	
	int& h =e;*/
	            //�κ�����ת������������ʱ����
				//����c�� �����������Ϳ�����ʽת���Ĺ���
				//�����ʱ��������ֵ�����г���
				//ֻ���� const& ���� &&������
//////////////////////////////////////////////////////////////////////////////////////
	//�Զ���������ʽת��Ϊ�������ͣ������������ͣ�
	//Ҫ����������ת�������
	int x = d;//int
	if(d)//������ʽ����ת��Ϊboolֵ
	printf("\n%d\n", x);
	return 0;
}