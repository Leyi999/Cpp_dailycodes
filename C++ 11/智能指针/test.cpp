#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"smartptr.h"
using namespace std;
template<class T>
//C++ û������������ �����ڴ�й©
//1.�����ͷ�
//2.delete֮ǰ���쳣�����ͷ���� 
//����RAII˼�� ���
//RAII:
//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ,����ʱ�����Դ������ʱ�ͷ���Դ��
//RAII ˼��Ϊ����ָ���ָ��˼�룬������������ָ��
//RAII ���������� ������ �Ⱥܶ��������� �� �� -> ������ ������Դ -> �ͷ���Դ�� ��->�ء�
//����ָ�� ��
//			1.RAII˼�� �����������ڹ����ͷ���Դ
//			2.����ָ��һ��ʹ��
//�����Լ�ʵ��һ�� RAII˼�������ָ��
class SmartPtr {
public:
	//RAII ˼��
	//����Դ�йܸ��������ö�����������ڹ����ͷ���Դ,����ʱ�����Դ������ʱ�ͷ���Դ��
	SmartPtr(const T* ptr)
		:_ptr(ptr) {
		;
	}
	~SmartPtr() { delete _ptr;/*���ﲻ���пգ�delete���� ����ǿվͲ��ͷ� Ҳ���������쳣*/ }
	//��ָ��һ��ʹ��
	SmartPtr(SmartPtr<T>& sp) =delete;
	SmartPtr<T>& operator=(SmartPtr<T>& sp) = delete;
	T& operator*() { return *_ptr; }
	T* operator->() { return &(*_ptr); }
	T* get() { return _ptr; }
private:
	T* _ptr;
};
//����ʵ������������ ��������  �Լ� delete �� delete[] -> ����ɾ�������º��������Ĭ����delete���ο�smartptr.h 
//					|
//				���ֿ������⣺������˭������Դ��
//				C++ 98 auto_ptr: ����Ȩת�ƣ��������������ÿգ�һ�����þͳ���  ������ �������Ա�Ĺ��� ->�ܶ๫˾��ȷҪ������ʹ��auto_ptr
//					|																	/*SmartPtr(SmartPtr<T>& sp) 
//					|																		:_ptr(sp._ptr) { sp._ptr = nullptr; }*/
//				boost��                   scoped_ptr  shared_ptr  weak_ptr...	->  boost Ϊ �б�׼ίԱ���Ա����д�ĵ������� ��C++��׼��ĺ󱸣�׼��׼�⣩��׼�������澫�������õ���׼���� ���ڸ���
//				C++ 11 ��׼��<memory>	  unique_ptr  shared_ptr  weak_ptr		->	boost������ȡ���������ԸĽ������� 
//					|
//					|				
////////////////////////////////////////////////////////       
// scoped_ptr -> c++11 unique_ptr  
//       �ص㣺�������� �򵥴ֱ� �㿽�����ܳ����� �ҾͲ����㿽��
//int main() {
//	unique_ptr<int> sp1(new int);	   //ʵ�ַ�ʽһ :ֻ���� ��ʵ��
//	*sp1 = 1;						   //  C++98 ��boost��
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
// �������� ��һ����̬��map<��ַ��count>//�Դ� ���У�������������ָ��������ۻ������Խ��ܣ����߳����������۸���������hashmap����������������ָ������ͷ���Դ
// �������� ���һ�� int *pcount �����ʱ��newһ��count ������ʱ��--(*pcount) //����
//template<class T>
//unordered_map<T*, int>s_m_SmartPtr<T>::_umap;//��ʼ����̬��Ա
//int main() {
//	//��������ʽ��δ��������
//	//s_SmartPtr<int>sp1(new int);
//	//s_SmartPtr<int >sp2(sp1);
//	//s_SmartPtr<int>sp3(new int);
//	//sp2 = sp3;
//	//return 0;
//	//���������Ժ�û����
//	s_m_SmartPtr<int>sp1(new int);
//	s_m_SmartPtr<int >sp2(sp1);
//	s_m_SmartPtr<int>sp3(new int);
//	sp2 = sp3;
//	return 0;
//}
// ����shared_ptr ��һ������������ -> ѭ������!
// �Ե������´���
// struct List {
//	shared_ptr<List> pev;
//	shared_ptr<List> next;
//	int x=0;
//};
//int main() {
//	shared_ptr<List> sp1(new List);
//	shared_ptr<List> sp2(new List);
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	//���ﹹ��ѭ������
//	sp1->next = sp2;
//	sp2->next = sp1;
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	return 0;//���������ڽ���ʱ�����ڵ㶼�����ͷ�
//			 //��������ʱ���Ǽ���1 ,��Ϊ�˴˹���˴�����������һ����������һ���������ڵ㶼���Գɹ��ͷš�
//}
////////////////////////////////////////////////////////////////////////////////////////
//  weak_ptr ->ר�Ž��shared_ptr��ѭ����������
//  �ص�:  ��RAII �ܷ��ʶ�д��Դ ������������ͷţ�
//		   ֻ�ṩ�޲εĹ����Լ�share_ptr�Ŀ�������͸�ֵ���� ģ��ʵ�ּ�smartptr.h
// ��ʹ��shared_ptrʱ ����Ҫ���������Դ�ͷŵ�ָ�����weak_ptr��
// �Ե�ʹ��weak_ptr��Ĵ��� �����shared_ptr ѭ�����õ�����
// struct List {
//	w_SmartPtr<List> pev;//��weak_ptr ����������Դ�ͷŹ���
//	w_SmartPtr<List> next;
//};
//int main() {
//	s_SmartPtr<List> sp1(new List);
//	s_SmartPtr<List> sp2(new List);
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	//���ﲻ���ɹ���ѭ������ 
//	sp1->next = sp2;
//	sp2->next = sp1;
//	cout << sp1.use_count() << "  " << sp2.use_count() << endl;
//	return 0;//���������ڽ���ʱ�����ڵ� ���� sp2 -> sp1 ��˳��˳������
//}
// /////////////////////////////////
// ���Զ���ɾ����
//template<class T>
//struct DeleteArr
//{
//	void operator()(T* arr) {
//		delete[]arr;
//	}
//};
//int main() {
//	u_SmartPtr<int,DeleteArr<int>>sp1(new int[10]{1,9,7,6,4,8,2,3,4,5});
//	for (int i = 0; i < 10; i++)
//		cout << sp1.get()[i] << ' ';
//	return 0;
//}
// 
///////////////////////////////////////////////////
// ����shared_ptr ����ɾ�����ķ���
int main() {
	int* ptr = static_cast<int*>(calloc(10, 4));
	shared_ptr<int>(ptr, [](int* p) {free(p); cout << "free"; });//������
	return 0;
}
// unique_ptr ������ʵ�ֵ�һ����ʵ����ʱ����º������� �Ͳ���ʾ��
//