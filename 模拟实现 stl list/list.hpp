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
//��߸�����
//iterator �� const_iterator����ģ��
//����Ҫ�б仯���Ｖ���һ��ģ�����
//template<typename T,typename Ref,typename Ptr>
template<typename T, typename Ref, typename Ptr>
struct list_iterator {
	typedef list_node<T> Node;
	typedef list_iterator self;
	typedef Ref Ref;
	typedef Ptr Ptr;
	//����д��������͸�ֵ���� Ĭ�����ɵ�ǳ����������
	//����д����������ֻ�ǽ���_pnode���ʽڵ� �����ͷ�
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
	//const����const &
	//ͨ������list����begin()��end()���������ɲ�ͬ�ĵ�����
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
	void emptyinit() //������ԭ��
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
	////��ͳд��
	//list<T>(const list& ls) {
	//	emptyinit();
	//	for (auto e : ls)
	//		push_back(e);
	//}
	//�ִ�д��
	list<T>(const list& ls) {
		emptyinit();//��������Ȱ��ڱ��ڵ����
		//��Ȼ�����������������ֵ ֱ��g

		list<T>tmp(ls.begin(), ls.end());//����
		swap(tmp);//ǳ����
	}
	//��ͳд��
	//list<T>& operator =(const list& ls) {
	//	emptyinit();
	//	for (auto e : ls)
	//		push_back(e);
	//	return *this;
	//}
	//�ִ�д��
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
		//return _head->_next; ����дҲ���� ����������explicit�Ĺ��캯��֧����ʽ����ת��
	}
	iterator begin() {
		return iterator(_head->_next);
		//return _head->_next; ����дҲ���� ����������explicit�Ĺ��캯��֧����ʽ����ת��
	}
	iterator end() {
		return iterator(_head);
	}
	const_iterator end()const {
		return const_iterator(_head);
		//return _head->_next; ����дҲ���� ����������explicit�Ĺ��캯��֧����ʽ����ת��
	}
	//���������
	const_reverse_iterator rbegin()const {
		//return const_reverse_iterator(end());
		return end();//���ι������ʽ����ת��
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
		//����
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
		//return erase(_head->_pev);//��ʽת��
	}
	iterator pop_front() {
		return erase(begin());
		//return erase(_head->_next);//��ʽת��
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
		//��ʽ����ת�� ��д��Ҳ����
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