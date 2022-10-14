#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
int main() {
	int a = 1, b = 4;
	Date d1;
	cin >> d1;
	cout<< (d1 += 21);
	return 0;
}