#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
using namespace std;
//////////////////////////////////////////
//	unique_ptr
//
template<class T>
class u_SmartPtr {
public:
	//RAII ˼��
	//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ
	u_SmartPtr(const T* ptr)
		:_ptr(ptr) {
		;
	}
	~u_SmartPtr() { delete _ptr; }/*���ﲻ���пգ�delete���� ����ǿվͲ��ͷ� Ҳ���������쳣*/

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
//���� shared_ptr 3 ���Ժ�û����
template<class T>
class s_SmartPtr {
public:
	//RAII ˼��
	//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ
	s_SmartPtr(T* ptr):_ptr(ptr), _pcount(new int{1}){;}
	~s_SmartPtr() {
		/*���ﲻ���пգ�delete���� ����ǿվͲ��ͷ� Ҳ���������쳣*/
		if (!--(*_pcount)) {
			delete _ptr;
			delete _pcount;
		}
	}
	s_SmartPtr(s_SmartPtr<T>& sp) 
	:_ptr(sp._ptr),_pcount(sp._pcount){(*_pcount)++;}

	s_SmartPtr<T>& operator = (s_SmartPtr<T>& sp) {
		if (sp._ptr == _ptr)
			return *this;
		if (!-- * (_pcount)) {
			delete _ptr;
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
private:
	T* _ptr;
	int* _pcount;
};
//////////////////////////////////////////////////
//�Լ��ķ���
// ������ 
//���Կ�û���� ����
//�����緽����
template<class T>
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
			delete _ptr;
		}
	}
	s_m_SmartPtr(s_m_SmartPtr<T>& sp)
		:_ptr(sp._ptr) {
		_umap[_ptr]++;
	}
	s_m_SmartPtr<T>& operator = (s_m_SmartPtr<T>& sp) {
		if (sp._ptr == _ptr)
			return *this;
		if (!-- (_umap[_ptr])) {
			_umap.erase(_ptr);
			delete _ptr;
		}
		_ptr = sp._ptr;
		_umap[_ptr]++;
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
private:
	static unordered_map<T*, int> _umap;
	T* _ptr;
};

