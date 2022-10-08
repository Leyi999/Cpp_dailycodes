#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<class T>
class A {
public:
	A(A&& b) {//移动构造 右值引用无法引用左值,可以重载自动匹配
		cout << "移动构造" << endl;
		std::swap(b._a, _a);
	}
	A( const A& b) {
		cout << "常规构造" << endl;
		_a = b._a;//常规拷贝构造 深拷贝的场景 如op+
	}
	A& operator =(A&& b) {//移动赋值 直接转移资源 让右值释放
		cout << "移动赋值" << endl;
		std::swap(b._a, _a);
		return *this;
	}
	A& operator =(A& b) {//常规赋值（现代写法）（可能是深拷贝）
						 //形参不能直接写成A b ，因为A 也可以接收右值，会引发错误
		cout << "常规赋值" << endl;

		A tmp(b);
		std::swap(tmp._a, _a);
		return *this;
	}
	A test(A&& a) {//第一次能识别 
					//传入后 a退化为左值
		//forward<A>(a);不能这样写，forward至是返回原本属性的引用不是更改为原本属性
		//A tmp(a);//move也一样，只是返回右值属性的引用
		A tmp(forward<A>(a));//使用forward返回原本的属性
		return tmp;
	}
	A test(const A& a) {
		A tmp(forward<const A/* const 形参要加const*/ >(a));
		return tmp;
	}
	void test2(const T& x) {
		cout << "left" << endl;
	}
	void test2(T&& xx) {//能正确重载 不是万能引用
		cout << "right" << endl;
	}
	A(const T& a=T())
		:_a(a){;}
	T _a;
};
A<int> func(const A<int>& b) {
	A<int> tmp(b._a);
	return tmp; //编译器优化一: 将tmp视为右值（将亡值）
			    //编译器优化二:直接移动构造c
				//不优化会先构造(tmp是左值，深拷贝)临时对象 再用临时对象移动构造/赋值（临时对象是将亡值） c
				//调式发现 优化二只适用于构造，移动赋值是先移动构造匿名对象再移动赋值c
		     	//不过至少不存在深拷贝 效率高
}

void __test(int& x) {
	cout << "left"<<endl;
}
void __test(int&& x) {
	cout << "right" << endl;
}
template<class T>
void test(T&& a) {//模板函数中 右值引用 变为万能引用 都可以接受 并退化为左值
	__test (forward<T>( a));//使用完美转发能正确识别
}
int main() {
	A<int> c = func(1);//移动构造
	c = func(2);//移动赋值
	A<int >d(c);
	cout << endl << endl;
	c.test(d);
	c.test(move(d));
	cout << endl << endl;
	int x = 1;
	c.test2(x);//类模板里右值引用不是万能引用
	c.test2(move(x));
	cout << endl << endl;
	test(x);//函数模板里右值引用是万能引用 并退化成左值
			//可使用完美转发解决问题
	test(move(1));
	
	return 0;
}