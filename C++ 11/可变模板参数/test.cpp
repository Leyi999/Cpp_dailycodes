#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<class T>
void __print( T&& t) {//����ʱ���� 
	std::cout << typeid(t).name() << ' ' << t << endl;
}
template<class ...T>
void print(T... args) {
	/*if (!sizeof...(args))
		return 0;*///��������д���ᱨ�� �ɱ�ģ�����չ�������ڱ���ʱ�;�����
	auto rl = { (__print(args),0)... };
	//�ȼ��� 
	/*initializer_list<int >il= {(__print(args), 0)...};*/
	cout << typeid(rl).name();//����C++ 11 initializer_list���������λ�ȡ������
}
int main() {
	print("123", "321", 0.123,999);
	return 0;
}