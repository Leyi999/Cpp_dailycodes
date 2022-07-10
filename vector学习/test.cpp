#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
<<<<<<< HEAD
#include<algorithm>

=======
>>>>>>> ef9c12eacbfe22e3bd0773cd453ed67a9d4458fb
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
<<<<<<< HEAD
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		cout << *it << ' ';
	cout << endl;
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++)
		cout << *rit << ' ';
	cout << endl;
	for (int& e : v1)
		cout << e << ' ';
	cout << endl;
	auto rd=v1.rbegin();
	cout << *rd;

	rd += 1;
	cout << *rd;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;


	//auto ed= (vector<int>::reverse_iterator)v1.begin();
	//cout << *ed;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	cout << *rd;

	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	rd += 1;
	if (rd == (vector<int>::reverse_iterator)v1.begin())
		cout << "rd==begin" << endl;
	if (rd == v1.rend())
		cout << "rd==rend" << endl;
	
	
=======
	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
		cout << *it << ' ';
	cout << endl;
	for (int& e : v1)
		cout << e << ' ';
>>>>>>> ef9c12eacbfe22e3bd0773cd453ed67a9d4458fb
	return 0;
}