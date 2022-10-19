#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class heap_only
{
	heap_only* get_obj(int n) {
		return new heap_only{ n };
	}
private:
	//heap_only& operator=(const heap_only& obj) = delete;
	heap_only(const heap_only& obj) = delete;
	heap_only(int n) :data(n){
	}
	int data;
};
class stack_only//���û�취��ֹ��̬��
{
	//����˽�� ���޷�������new ����Ҳ���ܵ���
	//��̬��Ա����ֱ��ͨ����������
	//�˽�ֵ���� ����������
	static stack_only create_obj(int n) {
		return stack_only(n);
	}
private:
	//������
	//�������Ĳ����ͷ���ֵ�ǹ̶��ģ�
	//void* operator new(size_t size) { ; }
	//void  operator delete(void* p) { ; }
	stack_only(int n) :data(n) { ; }
	int data;
};
//���ܱ���������
//  =delete =defaultֻ�в�д��Ĭ�����ɵĳ�Ա����������
//��������=delete
// 	heap_only(const heap_only& obj) = delete;
//���ܸ�ֵ����
//  heap_only& operator=(const heap_only& obj) = delete;
//���ܱ��̳е���
// c++98 ����˽��
//c ++ 11 �ؼ���final
class final_class final {
	;
};
//����ģʽ 
//����ģʽ
//һ��ʼ�ʹ��� �������ò��� ��ʡ�¶�
//ȱ���� ����ж������ �����ڲ�ͬ.c�ļ��� �޷����Ƴ�ʼ��˳�� ���һ��ǡ��������һ���ͱ���
class hungry_man {
public:
	hungry_man& get_instance(){
		return obj;
	}
	hungry_man& operator=(const hungry_man& obj) = delete;
	hungry_man (const hungry_man& obj) = delete;

private:
	//����Ϊ˽��
	hungry_man() = default;
	//����objֻ���ܵ�����������޶����޶��������Ǵ�������
	//����static������ĳ�Ա Ҳ����Ϊ����Ķ��� ���Է���˽��
	static hungry_man obj;
};
//cppȫ������ʾʵ����
hungry_man hungry_man::obj;
//����ģʽ
class lazy_man {
public:
	static lazy_man& get_instance() {
		//�ò� ��ʼ��
		if (!pobj)
			pobj = new lazy_man;
		return *pobj;
	}
	lazy_man& operator=(const lazy_man& obj) = delete;
	lazy_man(const lazy_man& obj) = delete;
	//��Ϊ�����ڶ��� �޷��Զ����� ����һ��������
	struct delete_class {
		~delete_class() {
			//�ڲ������ⲿ�����Ԫ �ܷ���pobj
			delete pobj;
		}
	};
private:
	//����Ϊ˽��
	lazy_man() = default;
	//��Ϊ�޷�����������Ҫ��̬
	static lazy_man* pobj;
};
lazy_man* lazy_man::pobj{nullptr};
lazy_man::delete_class dc;//����������ͷ���Դ
int main() {
	lazy_man::get_instance();
	return 0;
}