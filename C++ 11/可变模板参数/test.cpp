#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
template<class T>
void __print(const T& t) {//����ʱ���� 
	std::cout << t << ' ';
}
template<class ...T>
void print(T... args) {
	/*if (!sizeof...(args))
		return 0;*///��������д���ᱨ�� �ɱ�ģ�����չ�������ڱ���ʱ�;�����
	int arr[] = { (__print(args),0)... };
}
int main() {
	print("123", "321", 123);
	return 0;
}