#pragma once
#include<assert.h>
template<typename Valuetype,typename Container=vector<Valuetype>>
class queue {
public:
	void push(const Valuetype& val) {
		c.push_back(val);
	}
	void pop() {
		c.pop_front();
	}
	Valuetype front() {
		return c.front();
	}
	Valuetype back() {
		return c.back();
	}
	size_t size() {
		return c.size();
	}
	bool empty() {
		return c.empty();
	}
private:
	Container c;
};
