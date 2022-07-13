#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<assert.h>
template<class valuetype, class Container>
class stack {
public:
	void push(const valuetype& val) {
		_c.push_back(val);
	}
	void pop() {
		assert(!empty());
		_c.pop_back();
	}
	valuetype top() {
		assert(!empty());
		return _c.back();
	}
	size_t size() {
		return _c.size();
	}
	bool empty() {
		return _c.empty();
	}
private:
	Container _c;
};