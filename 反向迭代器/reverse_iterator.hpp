#pragma once
//萃取 实现一个萃取类 让这个类利用特化 处理不同类型，最后直接从萃取类里面拿结果
//使用萃取类就不用把Reverse_Iterator copy几个特化出来 
template<typename Iterator>
struct Iterator_traits {//自定义类型的iterator和const_iterator是两个类型所以不需要分开萃取（特化）
	typedef typename Iterator::Ref				Ref;
	typedef typename Iterator::Ptr				Ptr;
};
template<typename T>//原生指针的 const_iterator就是cosnt iterator 所以要分开萃取（特化）
struct Iterator_traits<T*> {
	typedef typename T&				Ref;
	typedef typename T*				Ptr;
};
template<typename T>
class Iterator_traits<const T*> {
	typedef typename const T& Ref;
	typedef typename const T* Ptr;
};
//template<typename Iterator,typename Ref,typename Ptr>
template<typename Iterator>
struct Reverse_Iterator {
	typedef typename Iterator_traits<Iterator>::Ref		Ref;
	typedef typename Iterator_traits<Iterator>::Ptr	    Ptr;

	typedef Reverse_Iterator Self;
	Reverse_Iterator(Iterator it=Iterator()) 
		:_cur(it)
	{
		;
	}
	//Ref operator*() {
	Ref operator*() {
		Iterator tmp(_cur);
		return *--tmp;
	}
	//Ptr operator->() {
	Ptr operator->() {
		return &(*_cur);
	}
	Self& operator++() {
		return --_cur;
	}
	Self operator++(int) {
		return _cur--;
	}
	Self& operator--() {
		return ++_cur;
	}
	Self operator--(int) {
		return _cur++;
	}
	bool operator!=(const Self rit)const {
		return _cur != rit._cur;
	}
	bool operator==(const Self rit)const {
		return _cur == rit._cur;
	}
	Iterator _cur;
};