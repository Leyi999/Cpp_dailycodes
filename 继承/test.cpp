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
//	teacher():person("����","��",19) {//�����ʼ������ǰ�������ȳ�ʼ���ø����Ա��ԭ�򣬹ʲ����ں������ڵ��ø��๹�캯����
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