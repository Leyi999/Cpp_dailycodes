#define _CRT_SECURE_NO_WARNINGS 1
#include"list.hpp"
#include"vector.hpp"
using namespace std;
using namespace mystl;
int main() {
	list<int> lt;
	vector<int>vt;
	for (int i = 0; i < 10; i++) {
		lt.push_back(i);
		vt.push_back(i);
	}
	for (auto it = lt.begin(); it != lt.end(); it++)
		cout << *it<<' ';
	cout << endl;
	for (list<int>::reverse_iterator rit = lt.rbegin(); rit != lt.rend(); rit++)
		cout << *rit << ' ';
	cout << endl;
	for (auto it = vt.begin(); it != vt.end(); it++) 
		cout << *it << ' ';
	cout << endl;
	for (vector<int>::reverse_iterator rit = vt.rbegin(); rit != vt.rend(); rit++)
		cout << *rit << ' ';
	return 0;
}