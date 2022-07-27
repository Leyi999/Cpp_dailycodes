#include<iostream>
using namespace std;
//class person {
//public:
//	person(int age) {
//		cout << "person age: " << age << endl;
//		_person_age = age;
//	}
//	int _person_age;
//};
//class teacher :virtual public person{
//public:
//	teacher(int age) :person(age), _teacher_id(123){
//		cout << "teacher p_age,id: " <<age <<' '<<_teacher_id << endl;
//	}
//	int _teacher_id;
//};
//class worker : public teacher {
//public:
//	worker() :_worker_id(666),teacher(20) ,person(30){
//		cout << "worker::person::age: " << teacher::_person_age;
//	}//最后派生类负责初始化直接基类和虚基类
//	int _worker_id ;
//};
class person {
public:
	void virtual print() {
		cout << "person" << endl;
	}
	int _person_age = 18;
};
class teacher :virtual public person {
public:
	void print() {
		cout << "teacher" << endl;
	}
	int teacher_id = 17;
};
class worker :virtual public person {
public:
	void print() {
		cout << "worker" << endl;
	}
};
class master :public teacher,public worker{
public:
	void print() {
		cout << "master" << endl;
	}
};



int main() {
	master m1;
	return 0;
}