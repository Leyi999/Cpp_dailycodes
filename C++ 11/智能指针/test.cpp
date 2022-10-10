#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"smartptr.h"
using namespace std;
template<class T>
class SmartPtr {
public:
	//RAII ˼��
	//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ
	SmartPtr(const T* ptr)
		:_ptr(ptr) {
		;
	}
	~SmartPtr() { delete _ptr;/*���ﲻ���пգ�delete���� ����ǿվͲ��ͷ� Ҳ���������쳣*/ }
	SmartPtr(SmartPtr<T>& sp) =delete;
	SmartPtr<T>& operator=(SmartPtr<T>& sp) = delete;
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
private:
	T* _ptr;
};
// ����ʵ������������
//
//1.�������� 
//��дĬ�ϵĿ���������ֵ����
//��̬�������
// �����������һ��ָ��
//����Ҳ�������
// Ҫ����ָ���λ��
//2.delete[] ���� delete ���ز�����[] 
// 
// 
//��������ν�� ��������
//C++ 98 std:: auto_ptr  
	/*SmartPtr(SmartPtr<T>& sp) 
	:_ptr(sp._ptr){sp._ptr = nullptr;}*/
// ����Ȩת�ƣ��������Ķ������� һ�����þͳ���  ������ �������Ա�Ĺ��� 
//  �ܶ๫˾Ҫ����ʹ��
//boost ��׼ίԱ���Աд�ĵ������� ��C++��׼��ĺ� ��׼�������澫�������õ���׼���� ���ڸ���
//boost  scoped_ptr shared_ptr weak_ptr 
//C++ 11 unique_ptr shared_ptr weak_ptr
//
////////////////////////////////////////////////////////       
// scoped_ptr -> c++11 unique_ptr  
//       �ص㣺�������� �򵥴ֱ� �㿽�����ܳ����� �ҾͲ����㿽��
//int main() {
//	unique_ptr<int> sp1(new int);	   //ʵ�ַ�ʽһ :ֻ���� ��ʵ��
//	*sp1 = 1;						   //  C++98
////unique_ptr<int> sp2(sp1);���벻ͨ��//  1.ֻ���� ��ʵ�� ������벻ͨ��
//	SmartPtr<int>msp1(new int);		   // SmartPtr(SmartPtr<T>&sp);   
//	SmartPtr<int>msp2(msp1);		   //  ���Ǻ��±�����ʵ��
//									   //  2.������˽��
//									   //  C++11
//									   // SmartPtr(SmartPtr<T>&sp) = delete;���˾͵�������   
//	return 0;						   //SmartPtr<T>& operator=(SmartPtr<T>& sp) = delete;
//}
//////////////////////////////////////////////////////////
// �����ܻ�����Ҫ�����ĳ���--> shared_ptr
// ����ԭ�����ü��� ������ʱ��--���� ���һ�������Ķ����ͷ���Դ
// //�����ʵ�ַǳ����� �����˺ܶ����� ����ģ��ʵ�������·���
// ����һ�� ��һ����̬�ĳ�Ա static int count  ����ʱ++ ����ʱ --Ϊ0ʱ�ͷ�
//			������ԭ�� ���г�Ա���в�������һ����Դ ƥ��һ��count
// �������� ��һ����̬��map<��ַ��count>//�Դ�
// �������� ���һ�� int *pcount �����ʱ��newһ��count ������ʱ��--(*pcount)
//
template<class T>
unordered_map<T*, int>s_m_SmartPtr<T>::_umap;
int main() {
	//��������ʽ��δ��������
	//s_SmartPtr<int>sp1(new int);
	//s_SmartPtr<int >sp2(sp1);
	//s_SmartPtr<int>sp3(new int);
	//sp2 = sp3;
	//return 0;
	//���������Ժ�û����
	s_m_SmartPtr<int>sp1(new int);
	s_m_SmartPtr<int >sp2(sp1);
	s_m_SmartPtr<int>sp3(new int);
	sp2 = sp3;
	return 0;
}