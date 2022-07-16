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
int main() {
	
	priority_queue<int,vector<int>,_greater<int>>pq;
	if (pq.empty()) {
		for (int i = 1; i <= 10; i++) {
			pq.push(i);
		}
		for (auto e : pq._c)
			printf("%d ", e);
		printf("\n");
		for (int i = 0; i < 10; i++) {
			pq.pop();
			for (auto e : pq._c)
				cout << e << ' ';
			cout << endl;
		}
	}
	//1字节占位，代价很小 可以说完美替代了函数指针
	cout << "sizeof _greater: "<<sizeof _greater<double><<" byte";
	return 0;
}