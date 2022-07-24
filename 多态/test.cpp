#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class  A{
public:
	void virtual func1() {
		cout << "func1 orgA" << endl;
	}
};
class B :  public A {
public:
	void virtual func1() {
		cout << "func1 B" << endl;
	}
};
class C : public A {
public:
	void virtual func1() {
		cout << "func1 C" << endl;
	}
};
//class C : public A {
//public:
//	void virtual func1() {
//		cout << "func1  overridedC" << endl;
//	}
//};
//class D : public B{
//public:
//	void virtual func2() {
//		cout << "func1  overridedC" << endl;
//	}
//	void func3() { cout << "1"; }
//};
int main() {
	B b1;
	C c1;
	return 0;
}