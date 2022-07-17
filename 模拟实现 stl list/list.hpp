#pragma once
#include<iostream>
#include<assert.h>
#include"reverse_iterator.hpp"
template<typename T>
struct list_node {
	list_node<T>(const T& val = T()) 
		:_next(nullptr), _pev(nullptr), _val(val) {
	}
	~list_node<T>(){

	}
	list_node* _next;
	list_node* _pev;
	T _val;	
};
//提高复用性
//iterator 和 const_iterator复用模板
//哪里要有变化哪里级添加一个模板参数
//template<typename T,typename Ref,typename Ptr>
template<typename T, typename Ref, typename Ptr>
struct list_iterator {
	typedef list_node<T> Node;
	typedef list_iterator self;
	typedef Ref Ref;
	typedef Ptr Ptr;
	//无需写拷贝构造和赋值重载 默认生成的浅拷贝够用了
	//无需写析构函数，只是借助_pnode访问节点 无需释放
	list_iterator<T,Ref,Ptr>(Node*const Pnode) : _Pnode(Pnode) {
		;
	}
	self& operator ++() {
		_Pnode = _Pnode->_next;
		return *this;
	}
	self operator ++(int) {
		self ret(*this);
		_Pnode = _Pnode->_next;
		return ret;
	}
	self& operator --() {
		_Pnode = _Pnode->_pev;
		return *this;
	}
	self operator --(int) {
		self ret(*this);
		_Pnode = _Pnode->_pev;
		return ret;
	}
	//const返回const &
	//通过重载list类中begin()和end()函数来生成不同的迭代器
	Ref operator *() {
		return _Pnode->_val;
	}
	Ptr operator ->() {
		return &_Pnode->_val;
	}
	bool operator !=(const self& it)const {
		return _Pnode != it._Pnode;
	}
	bool operator ==(const self& it)const {
		return _Pnode == it._Pnode;
	}

	Node* _Pnode;
};

template<typename T>
class list {
public:
	typedef list_iterator<T, T&, T*> iterator;
	typedef list_iterator<T, const T&, const T*>const_iterator;
	typedef Reverse_Iterator<iterator> reverse_iterator;
	typedef Reverse_Iterator<const_iterator> const_reverse_iterator;


	typedef list_node<T> Node;
	void emptyinit() //复用性原则
	{
		_head = new Node;
		_head->_next = _head;
		_head->_pev = _head;
	}
	list<T>()
	{
		emptyinit();
	}
	template <class InputIterator>
	list(InputIterator first, InputIterator last) {
		emptyinit();
		while (first != last) {
			push_back(*first);
			++first;
		}
	}
	void swap(list& ls) {
		std::swap(_head, ls._head);
	}
	////传统写法
	//list<T>(const list& ls) {
	//	emptyinit();
	//	for (auto e : ls)
	//		push_back(e);
	//}
	//现代写法
	list<T>(const list& ls) {
		emptyinit();//这里必须先把哨兵节点加上
		//不然交换后析构的是随机值 直接g

		list<T>tmp(ls.begin(), ls.end());//构造
		swap(tmp);//浅拷贝
	}
	//传统写法
	//list<T>& operator =(const list& ls) {
	//	emptyinit();
	//	for (auto e : ls)
	//		push_back(e);
	//	return *this;
	//}
	//现代写法
	list<T>& operator =(list ls) {
		swap(ls);
		return *this;
	}
	~list<T>() {
		if (_head) {
			clear();
			delete _head;
		}
	}
	const_iterator begin()const {
		return const_iterator(_head->_next);
		//return _head->_next; 这样写也可以 单参数不加explicit的构造函数支持隐式类型转换
	}
	iterator begin() {
		return iterator(_head->_next);
		//return _head->_next; 这样写也可以 单参数不加explicit的构造函数支持隐式类型转换
	}
	iterator end() {
		return iterator(_head);
	}
	const_iterator end()const {
		return const_iterator(_head);
		//return _head->_next; 这样写也可以 单参数不加explicit的构造函数支持隐式类型转换
	}
	//反向迭代器
	const_reverse_iterator rbegin()const {
		//return const_reverse_iterator(end());
		return end();//单参构造的隐式类型转换
	}
	reverse_iterator rbegin() {
		//return reverse_iterator(end());
		return end();
	}
	const_reverse_iterator rend()const {
		//return const_reverse_iterator(begin());
		return begin();
	}
	reverse_iterator rend(){
		//return reverse_iterator(begin());
		return begin();
	}
	iterator push_back(const T& val) {
		//复用
		/*Node* newnode = new Node(val);
		Node* tail = _head->_pev;
		tail->_next = newnode;
		_head->_pev = newnode;
		newnode->_pev = tail;
		newnode->_next = _head;*/
		return insert(end(), val);
	}
	iterator push_front(const T& val) {
		return insert(begin(), val);
	}
	iterator insert(iterator pos, const T& val) {
		Node* cur = pos._Pnode;
		Node* newnode = new Node(val);
		Node* pev = cur->_pev;
		pev->_next = newnode;
		newnode->_pev = pev;
		newnode->_next = cur;
		cur->_pev = newnode;
		return pos--;
	}
	iterator pop_back() {
		return erase(--end());
		//return erase(_head->_pev);//隐式转换
	}
	iterator pop_front() {
		return erase(begin());
		//return erase(_head->_next);//隐式转换
	}
	iterator erase(iterator pos ) {
		assert(pos!=end());
		//pos._Pnode->_pev->_next = pos._Pnode->_next;
		//pos._Pnode->_next->_pev = pos._Pnode->_pev;
		//Node* ret = pos._Pnode->_next;
		//delete pos._Pnode;
		//return iterator(ret);
		Node* cur = pos._Pnode;
		Node* pev = cur->_pev;
		Node* next = cur->_next;
		pev->_next = next;
		next->_pev = pev;
		return iterator(next);
		//隐式类型转换 此写法也可以
		//return next;
	}
	void clear() {
		iterator it = begin();
		while (it != end())
			it = erase(it);
	}
private:
	Node* _head;
};