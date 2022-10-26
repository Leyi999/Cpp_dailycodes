#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    int ns = 0;
    vector<int>fib;
    fib.push_back(1);
    fib.push_back(1);
    while (cin >> ns) {
        for (int i = 0; i < ns; i++) {
            int n;
            cin >> n;
            if (n > fib.size()) {
                for (int i = fib.size(); i <= n; i++) {
                    long long a = fib[i - 2];
                    long long b = fib[i - 1];
                    fib.push_back((a + b) % 10000);
                }
            }
            printf("%04d", fib[n]);
        }
        printf("\n");
    }
    return 0;
}