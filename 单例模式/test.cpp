#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//设计一个类 一个进程只能有一个实例化对象
//饿汉模式：1.程序开始前（main函数之前）初始化，简单方便
// 缺点 有多个单列模式的情况下 每个单列初始化顺序依赖编译器（如果在两个cpp里 谁先初始化？），如果有依赖关系要求初始化顺序容易出错
//		可能导致资源浪费（可能不用初始化）
//		static Sclass* get_instance() {return ptr;}
//      Sclass* Sclass::ptr{ new Sclass };
//懒汉模式：1.延迟初始化提高效率->程序启动变快（全局对象在main函数之前初始化）->可能不用初始化
//			2.有多个单例模式的情况下 每个单列初始化顺序可以自行代码控制
//一般情况下单列不需要释放 main函数结束了自动释放
//如果需要（比如在析构是向文件写入日志信息等）可以	1.自己加一个public函数delete this指针
//				2.内嵌一个内部类（垃圾回收器） 定义一个全局对象在单列的后面 main结束后在内部类析构时调用单列的析构（内部类是友元）不算RAII只是用到了类似的思想
//
class Sclass {
public:
	static Sclass* get_instance() {
		if (!ptr)
			ptr = new Sclass;
		return ptr;
	}
	void fix_data(int data) {
		_data = data;
	}
	Sclass(const Sclass&) = delete;
	int _data;
	//void Delete() {
	//	delete this;
	//	cout << "delete";
	//}
	struct rc {
		~rc() {
			delete ptr;//这里来调外部类的析构,只要ptr不为空（单例初始化过）就能调用到单例的析构
		}
	};
	~Sclass() {
		cout << "析构" << endl;
	}
private:
	Sclass() :_data(0){;}
	static Sclass* ptr;
};
Sclass* Sclass::ptr{ nullptr };
Sclass::rc rc;//注意顺序
int main() {
	//Sclass::get_instance()->Delete();
	cout << Sclass::get_instance()->_data<<endl;
	return 0;
}