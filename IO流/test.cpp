#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
struct date {
	date() = default;
	date(int year, int month, int day):_year(year), _month(month), _day(day){;}
	int _year = 1;
	int _month = 2;
	int _day = 3;
};
ostream& operator<<(ostream& out/*ostream <<����û��const�汾*/, const date& d) {
	return out << d._year << ' ' << d._month << ' ' << d._day << endl;//istream��>>�����ǿո���߻�������ʾ����ֵ�ļ��
}
istream& operator>>(istream& in, date& d/*���������βζ�������const����*/) {
	return in >> d._year >> d._month >> d._day;
}
int main() {
	// ��Ϊ����������� ������:���ֽڶ����ƶ�д �ı�:��ֵת���ַ���д�������ַ�������
	//��� �ն�/����̨���������
	//ostream istream <istream>
	//cout    cin ��i/ostreamȫ�ֵĶ��� <iostream> ��������istream �� ostream
	// ios_base::sync_with_stdio(false);//���ֻ�� cin��cout ���Թرո�stdio��ͬ�����Ч��
	//����ļ��� �������
	//ofstream ifstream �̳���i/ostream 
	//���Լ����������Ϊ��֪�����Ǹ��ļ� 
	//����ַ��������л� �����л����
	//istringstream ostringstream stringstream(���μ̳пɶ���д) <sstream>
	////������д��ȥ write <<
	//string str("12565");//��string��Σ�� �������ͬһ�����̶�д����
	//ofstream ofs("string.txt", ios_base::out|ios::binary );//�̳������� �ð�λ��Ϳ��Ե���״̬ //Ĭ��out
	//ofs.write(str.c_str(), str.size());//��const char*��size ������ʼ��ַ���ֽ��� ��Ϊ��ֱ�Ӱ��ֽڰ��ڴ�д��ȥ������const char*(�Զ������ͼǵ�ǿתһ��)
	///*ofs.flush()*/
	//ofs.close(); //һ�㲻���������� �����������Զ��� ���ǽ����ž�Ҫ��������ļ�
	//// �����ƶ�д֮ǰҪȷ����֮ǰ������ļ���i/ofstream�Ѿ�close�˻���flush��
	////�����ƶ��� read >>
	//ifstream ifs("string.txt", ios_base::in|ios::binary ); //Ĭ��in
	//string str_r;
	//str_r.resize(5);
	//ifs.read(const_cast<char*>(str_r.c_str()), 5);//��char*,size��Ҫд���λ�ã���ȡsize���ֽ�д��
	//cout << str_r;
	////�ı�д�� <<����ȡ���� put
	//ofstream ofs ("date.txt", ios_base::out/* | ios_base::binary*/);
	//date d1{2022,10,14};
	////ofs.write((const char*)&d1, sizeof(d1));
	//ofs << d1;//��11�� ������ostream��<<�������ofs��Ƭ���� �����ostream�����������<<���ء�->���ƻ������ostream�Ƿ�����Ƭ�������ο�����ת���е�dynamic_cast�� ��������д�����̨�ļ�����д�������ļ�
	//		  //���һ������ת���ַ���д��
	//ofs.close();//�ı�д���������޴���䲢������,��д������þ͹ر��ļ�
	////�ı����� >>get
	//ifstream ifs("date.txt", ios_base::in/* | ios_base::binary*/);
	//date d2;
	////ifs.read((char*)&d2,sizeof(d2));
	//ifs >> d2;
	//cout << d2;
	//���л���ת�ַ�����
	stringstream ss;
	date d1{2021,4,5};
	ss<<d1;
	//���л�
	cout << ss.str()<<endl;
	cout << typeid(ss.str()).name()<<endl;
	date d2;
	//ss.str("");//�ײ���һ��string <<���������string��׷�� ���������Գ�ʼ�����ss��
	cin >> d2;
	//�����л�
	cout << d2<<endl;

	return 0;
}