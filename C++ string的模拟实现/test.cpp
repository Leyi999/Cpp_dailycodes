#define _CRT_SECURE_NO_WARNINGS 1
#include"string.hpp"
using namespace std;
void test_pushback() {
	const String str1;
	String str2(str1);
	const String str3(str2);
	cout << str2.c_str() << endl;
	str2.pushback('c');
	cout << str2.c_str() << endl;
	str2.pushback('c');
	cout << str2.c_str() << endl;	str2.pushback('c');
	cout << str2.c_str() << endl;
}
void test_append() {
	const String str1("123");
	String str2(str1);
	const String str3(str2);
	str2.append("12312123132132132");
	cout << str2.c_str() << endl;
}
void test_resize() {
	const String str1("1");
	String str2(str1);
	const String str3(str2);
	str2 += "123";
	cout << str2.c_str() << endl;
	str2.resize(5, 'a');
	cout << str2.c_str() << endl;
	str2.resize(40, 'x');
	cout << str2.c_str() << endl;
	str2.resize(5, 'a');
	cout << str2.c_str() << endl;
}
int main() {
	test_resize();
	return 0;
}