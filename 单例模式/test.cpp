#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//���һ���� һ������ֻ����һ��ʵ��������
//����ģʽ��1.����ʼǰ��main����֮ǰ����ʼ�����򵥷���
// ȱ�� �ж������ģʽ������� ÿ�����г�ʼ��˳�����������������������cpp�� ˭�ȳ�ʼ�������������������ϵҪ���ʼ��˳�����׳���
//		���ܵ�����Դ�˷ѣ����ܲ��ó�ʼ����
//		static Sclass* get_instance() {return ptr;}
//      Sclass* Sclass::ptr{ new Sclass };
//����ģʽ��1.�ӳٳ�ʼ�����Ч��->����������죨ȫ�ֶ�����main����֮ǰ��ʼ����->���ܲ��ó�ʼ��
//			2.�ж������ģʽ������� ÿ�����г�ʼ��˳��������д������
//һ������µ��в���Ҫ�ͷ� main�����������Զ��ͷ�
//�����Ҫ�����������������ļ�д����־��Ϣ�ȣ�����	1.�Լ���һ��public����delete thisָ��
//				2.��Ƕһ���ڲ��ࣨ������������ ����һ��ȫ�ֶ����ڵ��еĺ��� main���������ڲ�������ʱ���õ��е��������ڲ�������Ԫ������RAIIֻ���õ������Ƶ�˼��
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
			delete ptr;//���������ⲿ�������,ֻҪptr��Ϊ�գ�������ʼ���������ܵ��õ�����������
		}
	};
	~Sclass() {
		cout << "����" << endl;
	}
private:
	Sclass() :_data(0){;}
	static Sclass* ptr;
};
Sclass* Sclass::ptr{ nullptr };
Sclass::rc rc;//ע��˳��
int main() {
	//Sclass::get_instance()->Delete();
	cout << Sclass::get_instance()->_data<<endl;
	return 0;
}