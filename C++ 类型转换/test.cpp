#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct A {
	virtual void f() {
		cout << "f" << endl;
	}
};
struct B :public A {
	//void f() {
	//	cout << "s"<<endl;
	//}
};
void print(A* ptr) {
	//(B*)ptr ����д����������������
	//reinterpret_cast<B*>(ptr)//����д���Ե��ǲ����鰲ȫ��
	if (dynamic_cast<B*>(ptr))//����Ҫ���������麯�� ����Ҫ��������д
		cout << "��ȫ��ת���ɹ�" << endl;
	else
		cout << "����ȫ���޷�ת������̬ת�����ؿ� "<<endl;//˵��ԭ����ָ�򸸵�ָ�� ��ת������� �Ͷ࿴�� ���ǲ���ȫ��
}
int main() {
	//C������ת�� 

	//��ʽ����ת��->������������ת��
	size_t a = 0;
	int b = 1;
	a = b;
	//ǿ������ת������ʾ�ģ�-> ���岻������
	int* p = (int*)a;

	//C++ϣ��������ӹ淶 ����Ҫ����C ���Բ�û��ǿ��Ҫ�����C�ķ�ʽ�����Ҳû���ձ�ʹ��C++���淶������ת���﷨������һЩ��˾��Ҫ��ġ�
	//������ת�� ��Ϊ���� static_cast  reinterpret_cast const_cast dynamic_cast
	// �÷� ..._cast<Ҫת�ɵ�����>�����ʽ��;
	// static:��ӦC����ʽ����ת��
	// reinterpret:��ӦC�� ���岻�������ͼ��ǿת
	// const ����C�а�constȥ����ǿת
	volatile const int c = 1;
	//int* pc = (int*)&c;
	int* pc = const_cast<int*>(&c);
	*pc = 2;
	cout << c<<endl;
	//         ���� ���������volatile ��ӡ������1 ��Ϊ��������Ϊ�㲻���޸�const���� ���о�û�д��ڴ�ȥȡ����ֱ�Ӵӳ�����ȥȡ�� ���߰�1���ڼĴ��� Ҫ��ӡֱ�ӴӼĴ���ȡ
	//                �������volatile ��Ҫ�� ����ȥ�ڴ���ȡ ��ӡ��������2��
	//  dynamic_cast(C++����): ���ܰ�ȫ����ת������ת�����ֵ�������ܷ���0;
	// Ҫ�� 1: ԭ��ָ���ӵ�ָ�루��ȫ��
	// Ҫ�� 2������д���麯��
	// Ӧ�ó���:
	A f;
	B s;
	print(&f);
	print(&s);
	//��� �ں���print��֪�� ptr�Ǳ�����ָ���໹�� ��������Ƭ���ɣ�
	//����15��

	  
	return 0;
}