#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
    static int Add(int num1, int num2) {
        int add1 = num1 ^ num2;//�������Ե��ӷ��� ��������Դ������ֻ���������ӷ�
        int add2 = (num1 & num2) << 1;
        while (add2) {//1100 -4  0100 4����λ��add1Ҳ������λԭ���ĵķ���λ��ʧ�� ����λ��add2 <<������λ�� �ͱ��ж�Ϊ-0 ����0
            int tmp = add1;
            add1 = add1 ^ add2;
            add2 = (tmp & add2) << 1;
        }
        return add1;
    }
};
int main() {
    int a{ 0 }, b{ 0 };
    cin >> a>> b;
    cout << Solution::Add(a, b);
}