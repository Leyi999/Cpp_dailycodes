#define _CRT_SECURE_NO_WARNINGS 1
#include"string.hpp"
#include<string>
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
	str2.append("#456789");
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
void test_ed() {
	const String str1("12345678910");
	//[index]
	for (unsigned int i = 0; i < str1.size(); i++) {
		cout << str1[i] << ' ';
	}
	cout << endl;
	//iterator
	for (auto it = str1.begin(); it != str1.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	//±éÀúfor
	for (auto& e : str1) {
		cout << e << ' ';
	}
	cout << endl;
}
void test_insert() {
	String str = "1234567";

	cout << str.insert(0,'0').c_str() << endl;
	cout << str.insert(8,'8').c_str() << endl;
	cout << (str += '9').c_str() << endl;
	cout << (str .insert(0, "###")).c_str() << endl;
	cout << (str.insert(str.size(), "***")).c_str() << endl;
	cout << (str.insert(str.size()/2, "!!!")).c_str() << endl;
}
void test_erase() {
	String str = "0123456789";
	cout << str.erase(1, 4).c_str() << endl;
}
void test_in() {
	String str;
	cin >> str;
	cout << str;
}
void func(const string& str) {
	cout << str;
}
int main() {
	//test_append();
	//test_in();
	//String str1 = "123";
	String str2 = "321";
	String str1 = str2;
	/*test_append();*/
	func("hehe");
	return 0;
}