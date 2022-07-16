#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<vector>
using namespace std;
//调试可以这么玩但是容器适配器本来就不支持遍历的
//template <typename Value_type, typename Container = vector<Value_type>, typename Iterator = vector<Value_type>::iterator, typename Compare = less<Value_type>>

template <typename Value_type,typename Container =vector<Value_type>,typename Compare=less<Value_type>>
class priority_queue {
public:
	//typedef Iterator iterator;
	//iterator begin() {
	//	return _c.begin();
	//}
	//iterator end() {
	//	return _c.end();
	//}
	priority_queue(const Compare& com = Compare())//兼容c的函数指针的玩法
		:_c(Container()), _cmp(com)
	{
		;
	}
	void _adjustup(size_t pos) {
		size_t parent = (pos - 1) / 2;
		while (pos>0&&_cmp(_c[parent] , _c[pos])) {
			swap(_c[parent], _c[pos]);
			pos = parent;
			parent = (pos - 1) / 2;
		}
	}
	void _adjustdown(size_t root) {
		//右孩子可能不存在但是左孩子必定存在?错误 root换到叶子节点处；
		//如何判断 root为叶子节点?看第一个儿子（左儿子）下标是否 < N（节点个数）
		//默认左孩子 方便判断root是否为叶子节点
		for (size_t child = root * 2 + 1; child < _c.size() && root < _c.size() - 1; child = root * 2 + 1) {
			//size_t child = (root * 2 + 2 < _c.size()-1 && _c[root * 2 + 2] > _c[root * 2 + 1]) ? root * 2 + 2 : root * 2 + 1;//默认左孩子;
			if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1]))//再判断右孩子是否存在 和是否需要更换孩子
				++child;
			if (_cmp(_c[root],_c[child])) {
				swap(_c[child], _c[root]);
				root = child;
			}
			else
				break;
		}
	}
	const Value_type& top()const {
		return _c.front();
	}
	void push(const Value_type& val) {
		_c.push_back(val);
		_adjustup(_c.size() - 1);
	}
	void pop() {
		assert(!_c.empty());
		std::swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		_adjustdown(0);
	}
	size_t size()const {
		return _c.size();
	}
	bool empty()const {
		return _c.empty();
	}
	//Container _c;方便调试
private:
	Container _c;
	Compare _cmp;

};