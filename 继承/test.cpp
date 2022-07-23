#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<string>
//using namespace std;
//class person {
//public:
//	person(const char* name,const char* sex,int age):_name(name),_sex(sex),_age(age) { ; }
//	void print() {
//		cout << _name << ' ' << _sex << ' ' << _age << ' '  << endl;
//	}
//private:
//	string _name;
//	int _age;
//	string _sex;
//};
//class teacher :virtual public person {
//public:
//	teacher():person("张三","男",19) {//满足初始化子类前，必须先初始化好父类成员的原则，故不能在函数体内调用父类构造函数。
//		;
//	}
//	~teacher() {
//		;
//	}
//};
#include<iostream>
#include<string>
using namespace std;
class person {
public:
	person(int age) : _age(age) { ; }
private:
	int _age;
};
class teacher : virtual public person {
public:
	teacher(int age) :person(age) { ; }
};
class student : virtual public person {
public:
	student(int age) :person(age) { ; }
};
class worker :public teacher, public student {
public:
	worker() :_age(20),teacher(19),student(20),person(30){ ; }
	int _age;
};

//class student : public person {
//public:
//	student() :person(17) { ; }
//};
//class worker : public teacher,public student {
//public:
//	worker()  {;}
//};

int main() {
	worker w1;
	return 0;
}