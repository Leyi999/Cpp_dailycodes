#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main() {
    char ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'Z')
            if ((ch -= 5) < 'A')
                ch += 26;
        cout << ch;
    }
}