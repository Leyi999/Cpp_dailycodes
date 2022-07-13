#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<list>
#include<iostream>
#include"queue.hpp"
using namespace std;
int main() {
	//vector 中不提供头插头删的接口
	//queue<int, vector<int>> q1;
	queue<int, list<int>> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	cout << q1.size()<<endl;
	for (size_t i = q1.size(); i > 0; i--) {
		cout << q1.front();
		q1.pop();
	}
	return 0;
}