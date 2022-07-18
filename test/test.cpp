#define _CRT_SECURE_NO_WARNINGS 1
#include"add.h"
#include<string>
#include<vector>
#include<iostream>
#define Container vector<int>
using namespace std;

template<class Type>
void Swap(Type a,Type b) {
	Type tmp(a);
	a = b;
	b = tmp;
}
template <typename T>
T add(T x, T y) {
	return x+y;
}
template<>
int add<int>(int x, int y) {
	return 666;
}
template <class T,size_t N>
struct arr {
	T& operator [](size_t pos) {
		return _arr[pos];
	}
	T _arr [N];
};

template <class T1,class T2>
class Test {
public:
	Test()
	{
		cout << "T1,T2" << endl;
	}
};
//ȫ�ػ�����Ψһһ������ʵ�������⴦�����ȼ����
template<>
class Test<int, int> {
public:
	Test() {
		cout << "int ,int" << endl;
	}
};
//ƫ�ػ�һ���Բ��ֲ������⴦��
template<class T1>//ֻҪ�ڶ�������Ϊint�Ķ����⴦��
class Test<T1, int> {
public:
	Test() {
		cout << "T1 ,int" << endl;
	}
};
//ƫ�ػ��� ���Բ�����һ�����ƣ�
template<class T1,class T2>//ֻҪ��������Ϊָ�����͵Ķ����⴦��
class Test<T1*, T2*> {
public:
	Test() {
		cout << "T1* ,T2*" << endl;
	}
};
int main() {
	Test<int,int> t1;
	Test<int*,int*> t2;
	Test<void*, int*> t3;
	int c = 1;
	double& rc = (double)c;
	return 0;
}

//int main() {
//	//char pstr[10] ;
//	//for (int i = 0; i < 10; i++) {
//	//	pstr[i] = i + 1;
//	//}
//	//for (auto e : pstr) {
//	//	printf("%d ", e);
//	//}
//	int arr[11] = {1,99,5,2,4,8,6,4,0,15,85};
//	//int arr[11];
//	//for (int i = 0; i < 11; i++) {
//	//	arr[i] = i;
//	//}
//	for (auto e : arr)
//		cout << e << ' ';
//	cout << endl;
//	//����д������ ��Ȼ����Ч��û�д�ͳд����
//	//for (auto& e : arr) {
//	//	for (auto& j : arr) {
//	//		if (j > e)
//	//			swap(j, e);
//	//	}
//	//	for (auto e : arr)
//	//		cout << e << ' ';
//	//	cout << endl;
//	//}
//	//�򵥺���� һ��n�ˣ�ÿһ�˺�һ����ǰһ���Ƚϣ�������
//	//ÿһ�˶��ܽ�һ����ֵ�ŵ�����λ��
//	//���������Ĳ���� ����ÿ�˺��ܼ��ٴ������� ��ð�ݲ���
//	for (int i = 0; i < 11; i++) {
//		for (int j = 1; j < 11; j++) {
//			if (arr[j] > arr[j-1])
//				swap(arr[j], arr[j-1]);
//		}
//		for (auto e : arr)
//			cout << e << ' ';
//		cout << endl;
//	}
//	return 0;
//
//
//
//	
//
//
//	
//}
//int main()
//
//{
//
//	Container cont = { 1, 2, 3, 4, 5 };
//
//	Container::iterator iter, tempIt;
//
//	for (iter = cont.begin(); iter != cont.end();)//��������ʧЧ �ڶ����жϵ�ʱ���ֱ�ӱ�������
//		//���ҳ������Դ���
//
//	{
//
//
//
//		tempIt = iter;
//
//
//
//		++iter;
//
//
//
//		cont.erase(tempIt);
//
//	}
//
//}