#pragma once
template<typename Iterator,typename Ref,typename Ptr>
struct Reverse_Iterator {
	typedef Reverse_Iterator Self;
	Reverse_Iterator(Iterator it=Iterator()) 
		:_cur(it)
	{
		;
	}
	Ref operator*() {
		Iterator tmp(_cur);
		return *--tmp;
	}
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