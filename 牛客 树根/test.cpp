#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>//∑¿÷π ˝Ã´¥Û
using namespace std;
int main() {
    string str;
    while (cin >> str) {
        while (str.size() != 1) {
            int sum = 0;
            for (auto e : str) {//¿€º”
                if (e)
                    sum += e - '0';
            }
            str = to_string(sum);
        }
        cout << str << endl;
    }
}