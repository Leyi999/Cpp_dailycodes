#define _CRT_SECURE_NO_WARNINGS 1
#include"list.hpp"
#include"reverse_iterator.hpp"
using namespace std;
int main() {
	list<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.push_back(4);
	x.push_front(0);
	////list <int >x2(x);
	//list<int >x2(x.begin(), x.end());
	//list <int >x3(x2);
	//for (auto it = x3.begin(); it != x3.end(); ++it)
	//	std::cout << *it;
	//cout << endl;
	//x.push_back(666);
	//x3 = x;
	//for (auto e : x3) {
	//	cout << e;
	//}
	//cout << endl;
	//x.pop_back();
	//x.pop_front();
	//for (auto e : x) {
	//	cout << e;
	//}
	//x.clear();

	for (auto rit = x.rbegin(); rit != x.rend();rit++)
		cout << *rit << ' ';
	return 0;
}