#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class A {
public:
	A(A&& b) {//�ƶ����� ��ֵ�����޷�������ֵ,���������Զ�ƥ��
		std::swap(b._a, _a);
	}
	A( const A& b) {
		_a = b._a;//���濽������ ����ĳ��� ��op+
	}
	A& operator =(A&& b) {//�ƶ���ֵ ֱ��ת����Դ ����ֵ�ͷ�
		std::swap(b._a, _a);
		return *this;
	}
	A& operator =(A& b) {//���渳ֵ���ִ�д�����������������
						 //�ββ���ֱ��д��A b ����ΪA Ҳ���Խ�����ֵ������������

		A tmp(b);
		std::swap(tmp._a, _a);
		return *this;
	}
	A(int a)
		:_a(a){;}
	int _a;
};
A func(const A& b) {
	A tmp(b._a);
	return tmp; //�������Ż�һ: ��tmp��Ϊ��ֵ������ֵ��
			    //�������Ż���:ֱ���ƶ�����c
				//���Ż����ȹ���(tmp����ֵ�����)��ʱ���� ������ʱ�����ƶ�����/��ֵ����ʱ�����ǽ���ֵ�� c
				//��ʽ���� �Ż���ֻ�����ڹ��죬�ƶ���ֵ�����ƶ����������������ƶ���ֵc
		     	//�������ٲ�������� Ч�ʸ�
}
int main() {
	A c = func(1);//�ƶ�����
	c = func(2);//�ƶ���ֵ
	return 0;
}