#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
#include<unordered_map>
#include<string>
using namespace std;
int add(int a, int b) {
	return a + b;
}
class puls {
	int pls(int a, int b) {
		return a + b;
	}
};
struct Add {
	int operator()(int a,int b){
		return a + b;
	}
};
class myclass {
public:
	static int sadd(int a, int b) {
		return a + b;
	}
	int cadd(int a, int b) {
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		return a + b;
	}
};
class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a + b;
	}
};

int main() {
	//��װ ����ֵ�β�һ�µ� ��ͬ���ͻ���ͬ���͵� �ɵ��ö���
	//�ײ��ÿɱ�ģ�����ʵ�� ����ģ��
	function<int(int, int)> f1 = add;
	function<int(int, int)>f2 = [](int a, int b) {return a + b; };
	function<int(int, int)>f3 = Add();
	//���Ա�еĺ�����װ
	//��Ҫ���һ��������Ͳ���
	//������ʹ�������������ȥ���� myclass ����thisָ��(�Ʋ�) 
	function<int(myclass, int, int)>f4 = &myclass::cadd;//����ǰȡ��ַ���﷨�涨
	//���о�̬��Ա������װʱ ����������Ͳ���������ǰҲ����Ҫȡ��ַ��ȡ��ַҲ�ɲ�����
	function<int(int, int)>f5 = /*&*/ myclass::sadd;

	//bind ����ģ��
	//������bind��������������������ѭ��  ��һ������ΪҪ��װ�Ķ��󣬺�����Ը���Ҫʡ�ԵĲ������͵���˳��
	//placeholders��std��������ռ� _1 _2�������Ĳ���ѭ�򣬿���_2 _1�ͽ�����ѭ�� 
	//ʡ�Ը���
	function<int(int, int)> f6 = bind(&myclass::cadd, myclass(),placeholders::_1,placeholders::_2);
	std::cout <<f6(1, 2)<<endl;
	//�ı�ѭ��
	function<int(int, int)> f7 = bind(myclass::sadd, placeholders::_2, placeholders::_1);
	std::cout << f7(2, 1);

	//ʹ�ó��� 
	//���� ��Ӧ ����
	// ��oj�� �沨�����ʽ��ֵ
	// #include<stack>
	//#include<iostream>
	//#include<functional>
	//#include<unordered_map>
	//	using namespace std;
	//	class Solution {
	//	public:
	//		int evalRPN(vector<string>& tokens) {
	//			unordered_map<string, function<long long(long long, long long)>> umap;
	//			umap["+"] = [](long long a, long long b) {return a + b; };
	//			umap["-"] = [](long long a, long long b) {return a - b; };
	//			umap["*"] = [](long long a, long long b) {return a * b; };
	//			umap["/"] = [](long long a, long long b) {return a / b; };
	//			stack<long long> st1;
	//			for (auto& e : tokens) {
	//				if (e != "+" && e != "-" && e != "*" && e != "/") {
	//					st1.push(stoi(e));
	//				}
	//				else {
	//					long long b = st1.top();//����b����a ��֤���Ҳ�������ȷ
	//					st1.pop();
	//					long long a = st1.top();
	//					st1.pop();
	//					st1.push(umap[e](a, b));
	//				}
	//			}
	//			return st1.top();
	//		}
	//	};
	//
	unordered_map<string, function<int(int, int)>> opumap;
	opumap["����ָ��"] = f1;
	opumap["lambda���ʽ"] = f2;
	opumap["�º���"] = f3;
	opumap["��Ǿ�̬��Ա����"] = f6;
	opumap["�ı��β�˳��ľ�̬��Ա����"] = f7;
	//����ָ��ɵ��÷��� �Ѳ�ͬ������װ����ͬ���� �����ϣmap���ߺ����map
	//�������ֻ���ṩ˼· ��ʵ���Ǽӷ�hh
	cout << endl << opumap["�º���"](666, 333)<<endl;
	return 0;
}