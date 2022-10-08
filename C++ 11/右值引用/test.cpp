#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<class T>
class A {
public:
	A(A&& b) {//�ƶ����� ��ֵ�����޷�������ֵ,���������Զ�ƥ��
		cout << "�ƶ�����" << endl;
		std::swap(b._a, _a);
	}
	A( const A& b) {
		cout << "���湹��" << endl;
		_a = b._a;//���濽������ ����ĳ��� ��op+
	}
	A& operator =(A&& b) {//�ƶ���ֵ ֱ��ת����Դ ����ֵ�ͷ�
		cout << "�ƶ���ֵ" << endl;
		std::swap(b._a, _a);
		return *this;
	}
	A& operator =(A& b) {//���渳ֵ���ִ�д�����������������
						 //�ββ���ֱ��д��A b ����ΪA Ҳ���Խ�����ֵ������������
		cout << "���渳ֵ" << endl;

		A tmp(b);
		std::swap(tmp._a, _a);
		return *this;
	}
	A test(A&& a) {//��һ����ʶ�� 
					//����� a�˻�Ϊ��ֵ
		//forward<A>(a);��������д��forward���Ƿ���ԭ�����Ե����ò��Ǹ���Ϊԭ������
		//A tmp(a);//moveҲһ����ֻ�Ƿ�����ֵ���Ե�����
		A tmp(forward<A>(a));//ʹ��forward����ԭ��������
		return tmp;
	}
	A test(const A& a) {
		A tmp(forward<const A/* const �β�Ҫ��const*/ >(a));
		return tmp;
	}
	void test2(const T& x) {
		cout << "left" << endl;
	}
	void test2(T&& xx) {//����ȷ���� ������������
		cout << "right" << endl;
	}
	A(const T& a=T())
		:_a(a){;}
	T _a;
};
A<int> func(const A<int>& b) {
	A<int> tmp(b._a);
	return tmp; //�������Ż�һ: ��tmp��Ϊ��ֵ������ֵ��
			    //�������Ż���:ֱ���ƶ�����c
				//���Ż����ȹ���(tmp����ֵ�����)��ʱ���� ������ʱ�����ƶ�����/��ֵ����ʱ�����ǽ���ֵ�� c
				//��ʽ���� �Ż���ֻ�����ڹ��죬�ƶ���ֵ�����ƶ����������������ƶ���ֵc
		     	//�������ٲ�������� Ч�ʸ�
}

void __test(int& x) {
	cout << "left"<<endl;
}
void __test(int&& x) {
	cout << "right" << endl;
}
template<class T>
void test(T&& a) {//ģ�庯���� ��ֵ���� ��Ϊ�������� �����Խ��� ���˻�Ϊ��ֵ
	__test (forward<T>( a));//ʹ������ת������ȷʶ��
}
int main() {
	A<int> c = func(1);//�ƶ�����
	c = func(2);//�ƶ���ֵ
	A<int >d(c);
	cout << endl << endl;
	c.test(d);
	c.test(move(d));
	cout << endl << endl;
	int x = 1;
	c.test2(x);//��ģ������ֵ���ò�����������
	c.test2(move(x));
	cout << endl << endl;
	test(x);//����ģ������ֵ�������������� ���˻�����ֵ
			//��ʹ������ת���������
	test(move(1));
	
	return 0;
}