#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
using namespace std;
/////////////////////////////////////////
// ����ɾ����
// �����㴫��ķº������ɶ�����ʵ������Ҫ��ɾ����ʽ
// �Լ�д�º��������͹���������ʱֻ�����ɶ������֮
// Ĭ�� delete
// �����shared_ptr�ڹ��캯�������󣬿�֧��lambda���ʽ ����ʵ�ֺܸ��� ���ǿ����unique_ptrһ����ģ�����������
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
	//RAII ˼��
	//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ
	u_SmartPtr(T* ptr)
		:_ptr(ptr) {
		;
	}
	~u_SmartPtr() { D d;d( _ptr); }/*���ﲻ���пգ�delete���� ����ǿվͲ��ͷ� Ҳ���������쳣*/

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
//������ ->�Լ��ķ���
//���Կ�û���� ����
//�����緽����
template<class T,class D=Delete<T>>
class s_m_SmartPtr {
public:
	//RAII ˼��
	//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ
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
//���� 3 ���Ժ�û����
template<class T,class D = Delete<T>>
class s_SmartPtr {
public:
	//RAII ˼��
	//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ
	s_SmartPtr(T* ptr):_ptr(ptr), _pcount(new int{1}){;}
	~s_SmartPtr() {
		/*���ﲻ���пգ�delete���� ����ǿվͲ��ͷ� Ҳ���������쳣*/
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


