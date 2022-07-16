#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<vector>
using namespace std;
template <typename Value_type,typename Container =vector<Value_type>,typename Compare=less<Value_type>>
class priority_queue {
public:
	void _adjustup(size_t pos) {
		Compare cmp;
		size_t parent = (pos - 1) / 2;
		while (pos>0&&cmp(_c[parent] , _c[pos])) {
			swap(_c[parent], _c[pos]);
			pos = parent;
			parent = (pos - 1) / 2;
		}
	}
	void _adjustdown(size_t root) {
		Compare cmp;
		//右孩子可能不存在但是左孩子必定存在?错误 root换到叶子节点处；
		//如何判断 root为叶子节点?看第一个儿子（左儿子）下标是否 < N（节点个数）
		//默认左孩子 方便判断root是否为叶子节点
		for (size_t child = root * 2 + 1; child < _c.size() && root < _c.size() - 1; child = root * 2 + 1) {
			//size_t child = (root * 2 + 2 < _c.size()-1 && _c[root * 2 + 2] > _c[root * 2 + 1]) ? root * 2 + 2 : root * 2 + 1;//默认左孩子;
			if (child + 1 < _c.size() && cmp(_c[child], _c[child + 1]))//再判断右孩子是否存在 和是否需要更换孩子
				++child;
			if (cmp(_c[root],_c[child])) {
				swap(_c[child], _c[root]);
				root = child;
			}
			else
				break;
		}
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
	size_t size() {
		return _c.size();
	}
	bool empty() {
		return _c.empty();
	}

	Container _c;
private:
};