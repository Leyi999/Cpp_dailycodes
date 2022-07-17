#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"Date.h"

template<typename T>
bool Less( T x,  T y) {
	return x < y;
};
//模板只支持全特化
//其实可以不特化直接写一个具体的就行（方案二）
//解决方案一 模板的特化（特殊处理）
template<>
bool Less<Date*>(Date* x, Date* y) {
	return *x < *y;
}

//解决方案二 直接写一个匹配的
//除非显示调用模板，编译器肯定会优先调用现成的
bool Less(Date* x, Date* y) {
	return *x < *y;
}
//template<>
//bool Less<Date>(Date* x, Date* y){//参数 和 形参要保持一致的变换 
//	return *x < *y;
//}

//如果不是const就不会调用特化，特化的类型必须严格匹配
//template<>
//bool IsEqual<const Date*>(const Date* left, const Date* right) {
//	return *left==*right;
//}
using namespace std;
//类模板的特化
template<class T1, class T2>
class Data {
public:
	Data() {
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//全特化
template<>
class Data<Date*, Date*> {
public:
	Data() {
		cout << "Data<Date*, Date*>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
//偏特化
template <class T1>
class Data<T1, int> {
public:
	Data() {
		cout << "Data<T1, int>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
//更进一步的偏特化
template <class T1,class T2>
class Data<T1*, T2*> {
public:
	Data() {
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
//模板会自动调用更匹配，更明确的那个
template <class T1 >
class Data<T1*, int*> {
public:
	Data() {
		cout << "Data<T1*, int*>" << endl;
	}
private:
	Date* _d1;
	Date* _d2;
};
////特化不能增加模板参数
//template <class T1, class T2,class T3>
//class Data<T1*, T2*,T3*> {
//public:
//	Data() {
//		cout << "Data<T1*, T2*,T3*>" << endl;
//	}
//private:
//	Date* _d1;
//	Date* _d2;
//	Date* _d3;
//};
int main() {
	Date* d1 = new Date(2021, 1, 2);
	Date* d2 = new Date(2021, 1, 2);
	Less<Date*>(d1, d2);
	Data<Date*, Date*> data1;
	Data<Date*, int*>date2;
	return 0;
}