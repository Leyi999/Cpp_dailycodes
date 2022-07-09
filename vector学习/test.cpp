#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main() {
	
	vector<int>v1;
	for(int i=0;i<=10;i++)
	v1.push_back(i);
	for (int i = 0; i <= 10; i++) 
		cout << v1[i] << ' ';
	cout << endl;
	for (int i = 0; i <= 10; i++)
		cout << v1.at(i) << ' ';
	cout << endl;
	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
		cout << *it << ' ';
	cout << endl;
	for (int& e : v1)
		cout << e << ' ';
	return 0;
}