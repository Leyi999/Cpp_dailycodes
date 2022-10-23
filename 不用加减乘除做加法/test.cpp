#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
    static int Add(int num1, int num2) {
        int add1 = num1 ^ num2;//减法可以当加法算 补码运算源码运算只能算正数加法
        int add2 = (num1 & num2) << 1;
        while (add2) {//1100 -4  0100 4不进位的add1也到符号位原本的的符号位丢失了 都进位的add2 <<到符号位了 就被判断为-0 就是0
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