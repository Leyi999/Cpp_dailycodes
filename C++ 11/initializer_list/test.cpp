#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.hpp"

#include<iostream>//��������<initializer_list>

using namespace mystl;
int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	auto al = { 1,2,3 };
	const vector<int>cv({ 1,2,3 });
	//const vector<int >cv={3,2,1};
	//�������Ĺ��� ��ʽ����ת��
	//1.�ȵ���cv��Ĭ�Ϲ���
	//2.����{}����һ��initializer_list ��������
	//3.�����������vt�Ĺ��죬����һ��vt��������
	//  ��ʵ3������ʽת��,�� initlistת��Ϊvt
	//4.�ٵ���vt�ĸ������� cv=����vt
	//һ��ᱻ�������Ż�Ϊֱ���� ���initlistȥ����vt ��������2,cv�Ĺ��� ==> const vector<int>({3,2,1});//Ҳ�Ͳ�����ʽת��
	//ע��{} ����initializer_list ��һ���Ǳ�׼�Լ�������ԭ��֧�ֵ�
	for (auto e : cv) {
		std::cout << e << " ";
	}
	cout << endl;
	v = { 4,5,6 };

	//�������
	//���ù��� ��initlist����һ��vt�������� ����ʽת����
	//�ø�ֵ����
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	//������
	string str = "123";
	str = "456";
	return 0;
}