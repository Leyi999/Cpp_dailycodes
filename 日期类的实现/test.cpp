#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
int main() {
	int a = 1, b = 4;
	Date d2(1983, 5, 21), d1(2030, 1, 31);

	cout<<d2- (d2 + 156160);
	
	return 0;
}