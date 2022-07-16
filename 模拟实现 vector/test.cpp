#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.hpp"
#include<iostream>
#include<algorithm>
using namespace mystl;
using namespace std;
void test1() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.resize(30, 0);
	for (auto e : v1)
		cout << e << ' ';
	v1.erase(find(v1.begin(), v1.end(), 6));
	cout << v1.capacity() << ' ' << v1.size();
	cout << endl;
	for (auto e : v1)
		cout << e << ' ';
}
void test2() {
	vector<int> v1;
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);
	v1.insert(v1.begin(), 1);

	v1.insert(v1.begin(),1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.resize(30, 0);
	for (auto e : v1)
		cout << e << ' ';
	cout << v1.capacity() << ' ' << v1.size();
}
void test3() {
	vector<int> v1;
	v1.resize(30, 0);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;

	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';
	cout << endl;
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
		cout << e << ' ';

	cout << v1.capacity() << ' ' << v1.size();
}
void test4() {

	vector<vector<string>>v;
	string str = "1234";
	vector<string> tv(1, str);
	tv.push_back(str);
	tv.push_back(str);

	v.push_back(tv);
	v.push_back(tv);
	v.push_back(tv);
	v.push_back(tv);
	//À©Èİ
	v.push_back(tv);
	v.push_back(tv);

	cout << v[4][2];
	//v2.push_back(v1);
	////v2.push_back("7");
	////v2.push_back("7");
	////v2.push_back("7");
	////v2.push_back("7");
	////v2.push_back("7");
	////v2.push_back("7");

	//vector<vector<string>>v4 = v2;
	//cout << endl;
	////for (auto e : v4)
	////	cout << e << ' ';
	//vector<int> v5(10, 3);


}
int main() {
	test4();
	return 0;
}