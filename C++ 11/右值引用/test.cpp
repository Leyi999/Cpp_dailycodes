#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class A {
public:
	A(A&& b) {//移动构造 右值引用无法引用左值,可以重载自动匹配
		std::swap(b._a, _a);
	}
	A( const A& b) {
		_a = b._a;//常规拷贝构造 深拷贝的场景 如op+
	}
	A& operator =(A&& b) {//移动赋值 直接转移资源 让右值释放
		std::swap(b._a, _a);
		return *this;
	}
	A& operator =(A& b) {//常规赋值（现代写法）（可能是深拷贝）
						 //形参不能直接写成A b ，因为A 也可以接收右值，会引发错误

		A tmp(b);
		std::swap(tmp._a, _a);
		return *this;
	}
	A(int a)
		:_a(a){;}
	int _a;
};
A func(const A& b) {
	A tmp(b._a);
	return tmp; //编译器优化一: 将tmp视为右值（将亡值）
			    //编译器优化二:直接移动构造c
				//不优化会先构造(tmp是左值，深拷贝)临时对象 再用临时对象移动构造/赋值（临时对象是将亡值） c
				//调式发现 优化二只适用于构造，移动赋值是先移动构造匿名对象再移动赋值c
		     	//不过至少不存在深拷贝 效率高
}
int main() {
	A c = func(1);//移动构造
	c = func(2);//移动赋值
	return 0;
}