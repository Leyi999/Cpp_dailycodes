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
ostream& operator<<(ostream& out/*ostream <<重载没有const版本*/, const date& d) {
	return out << d._year << ' ' << d._month << ' ' << d._day << endl;//istream的>>重载是空格或者换行来表示两个值的间隔
}
istream& operator>>(istream& in, date& d/*这里两个形参都不可是const修饰*/) {
	return in >> d._year >> d._month >> d._day;
}
int main() {
	// 分为两种输入输出 二进制:按字节二进制读写 文本:把值转成字符串写出，按字符串读入
	//针对 终端/控制台的输入输出
	//ostream istream <istream>
	//cout    cin 是i/ostream全局的对象 <iostream> 简介包含了istream 和 ostream
	// ios_base::sync_with_stdio(false);//如果只用 cin和cout 可以关闭更stdio的同步提高效率
	//针对文件的 输入输出
	//ofstream ifstream 继承了i/ostream 
	//需自己定义对象因为不知道打开那个文件 
	//针对字符串的序列化 反序列化输出
	//istringstream ostringstream stringstream(菱形继承可读可写) <sstream>
	////二进制写出去 write <<
	//string str("12565");//用string很危险 如果不是同一个进程读写勿用
	//ofstream ofs("string.txt", ios_base::out|ios::binary );//继承下来的 用按位或就可以叠加状态 //默认out
	//ofs.write(str.c_str(), str.size());//传const char*，size 代表起始地址和字节数 因为是直接按字节把内存写出去所以是const char*(自定义类型记得强转一下)
	///*ofs.flush()*/
	//ofs.close(); //一般不用主动调用 析构函数会自动关 除非紧接着就要读入这个文件
	//// 二进制读写之前要确保，之前打开这个文件的i/ofstream已经close了或者flush了
	////二进制读入 read >>
	//ifstream ifs("string.txt", ios_base::in|ios::binary ); //默认in
	//string str_r;
	//str_r.resize(5);
	//ifs.read(const_cast<char*>(str_r.c_str()), 5);//（char*,size）要写入的位置，读取size个字节写入
	//cout << str_r;
	////文本写出 <<流提取重载 put
	//ofstream ofs ("date.txt", ios_base::out/* | ios_base::binary*/);
	//date d1{2022,10,14};
	////ofs.write((const char*)&d1, sizeof(d1));
	//ofs << d1;//见11行 重载与ostream的<<运算符，ofs切片传参 后调用ostream里的内置类型<<重载。->估计会检查这个ostream是否是切片而来（参考类型转换中的dynamic_cast） 来决定是写入控制台文件还是写入其他文件
	//		  //最后一定都是转成字符串写出
	//ofs.close();//文本写出读入有无此语句并无区别,但写完了最好就关闭文件
	////文本读入 >>get
	//ifstream ifs("date.txt", ios_base::in/* | ios_base::binary*/);
	//date d2;
	////ifs.read((char*)&d2,sizeof(d2));
	//ifs >> d2;
	//cout << d2;
	//序列化（转字符串）
	stringstream ss;
	date d1{2021,4,5};
	ss<<d1;
	//序列化
	cout << ss.str()<<endl;
	cout << typeid(ss.str()).name()<<endl;
	date d2;
	//ss.str("");//底部是一个string <<就算往这个string里追加 这条语句可以初始化这个ss；
	cin >> d2;
	//反序列化
	cout << d2<<endl;

	return 0;
}