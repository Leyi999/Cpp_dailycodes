#define _CRT_SECURE_NO_WARNINGS 1
#include<list>
#include<vector>
#include"stack.hpp"
#include<iostream>
using namespace std;
int main(){
	stack<int, list<int>>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	size_t sz = st.size();
	for (size_t i = 0; i < sz; i++) {
		printf("%d", st.top());
		st.pop();
	}



	return 0;
}