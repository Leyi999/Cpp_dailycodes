#define _CRT_SECURE_NO_WARNINGS 1
#include"add.h"
#include<string>
#include<vector>
#include<iostream>
#define Container vector<int>
using namespace std;

template<class Type>
void Swap(Type a,Type b) {
	Type tmp(a);
	a = b;
	b = tmp;
}
template <typename T>
T add(T x, T y) {
	return x+y;
}
template<>
int add<int>(int x, int y) {
	return 666;
}
template <class T,size_t N>
struct arr {
	T& operator [](size_t pos) {
		return _arr[pos];
	}
	T _arr [N];
};

template <class T1,class T2>
class Test {
public:
	Test()
	{
		cout << "T1,T2" << endl;
	}
};
//全特化（对唯一一种特殊实例化特殊处理）优先级最高
template<>
class Test<int, int> {
public:
	Test() {
		cout << "int ,int" << endl;
	}
};
//偏特化一（对部分参数特殊处理）
template<class T1>//只要第二个参数为int的都特殊处理
class Test<T1, int> {
public:
	Test() {
		cout << "T1 ,int" << endl;
	}
};
//偏特化二 （对参数进一步限制）
template<class T1,class T2>//只要两个参数为指针类型的都特殊处理
class Test<T1*, T2*> {
public:
	Test() {
		cout << "T1* ,T2*" << endl;
	}
};
int main() {
	Test<int,int> t1;
	Test<int*,int*> t2;
	Test<void*, int*> t3;
	int c = 1;
	double& rc = (double)c;
	return 0;
}

//int main() {
//	//char pstr[10] ;
//	//for (int i = 0; i < 10; i++) {
//	//	pstr[i] = i + 1;
//	//}
//	//for (auto e : pstr) {
//	//	printf("%d ", e);
//	//}
//	int arr[11] = {1,99,5,2,4,8,6,4,0,15,85};
//	//int arr[11];
//	//for (int i = 0; i < 11; i++) {
//	//	arr[i] = i;
//	//}
//	for (auto e : arr)
//		cout << e << ' ';
//	cout << endl;
//	//这种写法很玄 虽然可以效率没有传统写法高
//	//for (auto& e : arr) {
//	//	for (auto& j : arr) {
//	//		if (j > e)
//	//			swap(j, e);
//	//	}
//	//	for (auto e : arr)
//	//		cout << e << ' ';
//	//	cout << endl;
//	//}
//	//简单好理解 一共n趟，每一趟后一个跟前一个比较，交换。
//	//每一趟都能将一个最值放到合适位置
//	//跟快排最大的差距再 快排每趟后都能减少待排区间 而冒泡不行
//	for (int i = 0; i < 11; i++) {
//		for (int j = 1; j < 11; j++) {
//			if (arr[j] > arr[j-1])
//				swap(arr[j], arr[j-1]);
//		}
//		for (auto e : arr)
//			cout << e << ' ';
//		cout << endl;
//	}
//	return 0;
//
//
//
//	
//
//
//	
//}
//int main()
//
//{
//
//	Container cont = { 1, 2, 3, 4, 5 };
//
//	Container::iterator iter, tempIt;
//
//	for (iter = cont.begin(); iter != cont.end();)//若迭代器失效 第二次判断的时候就直接被检查出来
//		//并且出发断言错误
//
//	{
//
//
//
//		tempIt = iter;
//
//
//
//		++iter;
//
//
//
//		cont.erase(tempIt);
//
//	}
//
//}