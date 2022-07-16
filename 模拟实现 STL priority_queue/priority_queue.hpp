#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<vector>
using namespace std;
//���Կ�����ô�浫�����������������Ͳ�֧�ֱ�����
//template <typename Value_type, typename Container = vector<Value_type>, typename Iterator = vector<Value_type>::iterator, typename Compare = less<Value_type>>

//��μ���c������ָ����÷���
//ģ����� Compare�����Զ��ƣ�1.�㴫����ָ���Ҿ��Ǻ���ָ������ �ٹ��캯��ʱ�㴫���ң��Ұ����㴫�ݸ��ҵĺ���ָ�룬��ʵ�����ҵıȽϳ�Ա��
//2.�㴫�º��� �Ҿ��Ƿº���������Զ������ͣ��ڹ���ʱ��Ĭ�ϵ���Compare��Ĭ�Ϲ��캯��ʵ������ûë����
//3.���������ģ�����������ָ������ �������ڹ���ʱ���Ѻ���ָ�봫���ң��Ǿͻ��Զ����ú���ָ���Ĭ�Ϲ������nullptr������
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
	priority_queue(const Compare& com = Compare())//����c�ĺ���ָ����淨
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
		//�Һ��ӿ��ܲ����ڵ������ӱض�����?���� root����Ҷ�ӽڵ㴦��
		//����ж� rootΪҶ�ӽڵ�?����һ�����ӣ�����ӣ��±��Ƿ� < N���ڵ������
		//Ĭ������ �����ж�root�Ƿ�ΪҶ�ӽڵ�
		for (size_t child = root * 2 + 1; child < _c.size() && root < _c.size() - 1; child = root * 2 + 1) {
			//size_t child = (root * 2 + 2 < _c.size()-1 && _c[root * 2 + 2] > _c[root * 2 + 1]) ? root * 2 + 2 : root * 2 + 1;//Ĭ������;
			if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1]))//���ж��Һ����Ƿ���� ���Ƿ���Ҫ��������
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
	//Container _c;����ʱ����������۲�����
private:
	Container _c;
	Compare _cmp;

};