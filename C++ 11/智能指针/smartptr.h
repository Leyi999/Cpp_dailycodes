#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
using namespace std;
/////////////////////////////////////////
// 定制删除器
// 根据你传入的仿函数生成对象来实现你想要的删除方式
// 自己写仿函数传类型过来，析构时只管生成对象调用之
// 默认 delete
// 库里的shared_ptr在构造函数传对象，可支持lambda表达式 但是实现很复杂 我们库里的unique_ptr一样传模板参数就行了
template<class T>
struct Delete {
	void operator()(T*ptr) {
		delete ptr;
	}
};
// 
//////////////////////////////////////////
//	unique_ptr
//
template<class T,class D=Delete<T>>
class u_SmartPtr {
public:
	//RAII 思想
	//把资源托管给对象，利用对象的声明周期管理释放资源
	u_SmartPtr(T* ptr)
		:_ptr(ptr) {
		;
	}
	~u_SmartPtr() { D d;d( _ptr); }/*这里不用判空，delete会检查 如果是空就不释放 也不报错不抛异常*/

	u_SmartPtr(u_SmartPtr<T>& sp) = delete;
	u_SmartPtr<T>& operator=(u_SmartPtr<T>& sp) = delete;
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
private:
	T* _ptr;
};
//////////////////////////////////////////////////////////////////////
// shared_ptr
//方案二 ->自己的方案
//调试看没问题 ！！
//但不如方案三
template<class T,class D=Delete<T>>
class s_m_SmartPtr {
public:
	//RAII 思想
	//把资源托管给对象，利用对象的声明周期管理释放资源
	s_m_SmartPtr(T* ptr) :_ptr(ptr) {
		_umap[_ptr]++;
	}
	~s_m_SmartPtr() {
		if (!--(_umap[_ptr])) {
			_umap.erase(_ptr);
			D d;
			d(_ptr);
		}
	}
	s_m_SmartPtr(s_m_SmartPtr<T>& sp)
		:_ptr(sp._ptr) {
		_umap[_ptr]++;
	}
	s_m_SmartPtr<T>& operator = (s_m_SmartPtr<T>& sp) {
		if (sp._ptr == _ptr)
			return *this;
		if (!--(_umap[_ptr])) {
			_umap.erase(_ptr);
			D d;
			d(_ptr);
		}
		_ptr = sp._ptr;
		_umap[_ptr]++;
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
	const T* get()const { return _ptr; }
	const int use_count()const { return _umap[_ptr]; }

private:
	static unordered_map<T*, int> _umap;
	T* _ptr;
};
//方案 3 调试后没问题
template<class T,class D = Delete<T>>
class s_SmartPtr {
public:
	//RAII 思想
	//把资源托管给对象，利用对象的声明周期管理释放资源
	s_SmartPtr(T* ptr):_ptr(ptr), _pcount(new int{1}){;}
	~s_SmartPtr() {
		/*这里不用判空，delete会检查 如果是空就不释放 也不报错不抛异常*/
		if (!--(*_pcount)) {
			D d;
			d( _ptr);
			delete _pcount;
		}
	}
	s_SmartPtr(s_SmartPtr<T>& sp) 
	:_ptr(sp._ptr),_pcount(sp._pcount){(*_pcount)++;}

	s_SmartPtr<T>& operator = (s_SmartPtr<T>& sp) {
		if (sp._ptr == _ptr)
			return *this;
		if (!-- * (_pcount)) {
			D d;
			d( _ptr);
			delete _pcount;
		}
		_ptr = sp._ptr;
		_pcount = sp._pcount;
		++(*_pcount);
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
	const T* get()const {return _ptr;}
	const int use_count()const { return *_pcount; }
private:
	T* _ptr;
	int* _pcount;
};
//////////////////////////////////////////////////////////
// weak_ptr
template<class T>
class w_SmartPtr {
public:
	w_SmartPtr() :_ptr(nullptr) { ; }
	w_SmartPtr(s_SmartPtr<T> sp) :_ptr(sp.get()){ ; }
	w_SmartPtr& operator =(s_SmartPtr<T> sp) {
		_ptr = sp.get();
		return *this;
	}
	w_SmartPtr& operator =(w_SmartPtr<T> sp) {
		_ptr = sp.get();
		return *this;
	}
	T* get() {
		return _ptr;
	}
	const T* get()const {
		return _ptr;
	}
private: 
	T* _ptr;
};


