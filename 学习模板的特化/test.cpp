#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"Date.h"

template<typename T>
bool Less( T x,  T y) {
	return x < y;
};
//ģ��ֻ֧��ȫ�ػ�
//��ʵ���Բ��ػ�ֱ��дһ������ľ��У���������
//�������һ ģ����ػ������⴦��
template<>
bool Less<Date*>(Date* x, Date* y) {
	return *x < *y;
}

//��������� ֱ��дһ��ƥ���
//������ʾ����ģ�壬�������϶������ȵ����ֳɵ�
bool Less(Date* x, Date* y) {
	return *x < *y;
}
//template<>
//bool Less<Date>(Date* x, Date* y){//���� �� �β�Ҫ����һ�µı任 
//	return *x < *y;
//}

//�������const�Ͳ�������ػ����ػ������ͱ����ϸ�ƥ��
//template<>
//bool IsEqual<const Date*>(const Date* left, const Date* right) {
//	return *left==*right;
//}
using namespace std;
//��ģ����ػ�
template<class T1, class T2>
class Data {
public:
	Data() {
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//ȫ�ػ�
template<>
class Data<Date*, Date*> {
public:
	Data() {
		cout << "Data<Date*, Date*>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
//ƫ�ػ�
template <class T1>
class Data<T1, int> {
public:
	Data() {
		cout << "Data<T1, int>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
//����һ����ƫ�ػ�
template <class T1,class T2>
class Data<T1*, T2*> {
public:
	Data() {
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
//ģ����Զ����ø�ƥ�䣬����ȷ���Ǹ�
template <class T1 >
class Data<T1*, int*> {
public:
	Data() {
		cout << "Data<T1*, int*>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
////�ػ���������ģ�����
//template <class T1, class T2,class T3>
//class Data<T1*, T2*,T3*> {
//public:
//	Data() {
//		cout << "Data<T1*, T2*,T3*>" << endl;
//	}
//private:
//	Date* _d1;
//	Date* _d2;
//	Date* _d3;
//};
int main() {
	Date* d1 = new Date(2021, 1, 2);
	Date* d2 = new Date(2021, 1, 2);
	Less<Date*>(d1, d2);
	Data<Date*, Date*> data1;
	Data<Date*, int*>date2;
	return 0;
}