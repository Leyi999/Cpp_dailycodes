#define _CRT_SECURE_NO_WARNINGS 1
#include"priority_queue.hpp"
using namespace std;

template<typename Value_type>
struct _less
{
	bool operator()(const Value_type x, const  Value_type y)const {
		return x < y;
	}
};
template<typename Value_type>
struct _greater
{
	bool operator()(const Value_type x, const Value_type y)const {
		return x > y;
	}
};
bool cmp_int_less(const int x, const  int y) {
	return x < y;
}
int main() {
	auto pf = &cmp_int_less;
	//������c���淨
	//priority_queue<int,vector<int>,bool(*)(const int,const int)>pq(cmp_int_less);
	//C++�淨
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	priority_queue<int, vector<int>, _less<int>>pq(arr,arr+10);
	// 
	//priority_queue<int>pq;
	//for (int i = 1; i <= 10; i++)
	//	pq.push(i);
		for (auto e : pq._c)
			printf("%d ", e);
		printf("\n");
		for (int i = 0; i < 10; i++) {
			pq.pop();
			for (auto e : pq._c)
				cout << e << ' ';
			cout << endl;
		}
	//1�ֽ�ռλ�����ۺ�С ����˵��������˺���ָ��
	cout << "sizeof _greater: "<<sizeof _greater<double><<" byte";
	return 0;
}