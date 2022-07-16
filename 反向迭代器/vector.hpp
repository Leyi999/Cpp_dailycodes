#pragma once
#include<string>
#include<assert.h>
#include"reverse_iterator.hpp"
namespace mystl {
	template<typename T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef Reverse_Iterator<iterator,T&,T*>reverse_iterator;
		typedef Reverse_Iterator<iterator,const T&,const T*>const_reverse_iterator;

		const_iterator begin()const {
			return _start;
		}
		iterator begin() {
			return _start;
		}
		const_iterator end()const {
			return _finsh;
		}
		iterator end() {
			return _finsh;
		}
		const_reverse_iterator rbegin()const {
			return end();
		}
		reverse_iterator rbegin() {
			return end();
		}
		const_reverse_iterator rend()const {
			return begin();
		}
		reverse_iterator rend() {
			return begin();
		}
		size_t size()const {
			return _finsh - _start;
		}
		size_t capacity()const {
			return _endofstoage - _start;
		}
		void swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_finsh, v._finsh);
			std::swap(_endofstoage, v._endofstoage);
		}
		vector<T>(int n, const T& val = T())
			: _start(0), _finsh(0), _endofstoage(0)
		{
			reserve(n);
			while (n--)
				push_back(val);
		}
		vector<T>(size_t n=0,const T& val=T())
			:_start(0), _finsh(0), _endofstoage(0)
		{
			reserve(n);
			while (n--)
				push_back(val);
		}
		template<typename InputIterator>
		vector<T>(InputIterator first,InputIterator last)
			: _start(0), _finsh(0), _endofstoage(0)
		{
			reserve(last - first);
			while (first != last)
				push_back(*first++);
		}
		vector<T>(const vector <T>& v) 
			:_start(0), _finsh(0), _endofstoage(0)
		{
			vector<T>tmp(v.begin(), v.end());
			swap(tmp);
		}
		vector<T>& operator =(vector<T>v) {
			swap(v);
			return *this;
		}
		~vector<T>() {
			if (_start)
				delete[]_start;
			_finsh = _endofstoage = 0;
		}
		void reserve(size_t n) {
			if (n < capacity())
				return;
			T* tmp = new T[n];
			size_t size = this->size();
			if (_start) {
				//这种写法会导致浅拷贝引发的问题
				// 当储存类型也为vector或者string等指向堆区空间的自定义类型时
				// memmove把数据浅拷贝到新空间，但是释放旧空间时会调用析构函数（因为new的是自定义类型）
				//析构函数会把新空间内指向的堆区空间释放 直接gg 
				//memmove(tmp, _start, size * sizeof(T));
				for (size_t i = 0; i < size; i++)
					tmp[i] = _start[i];//这种写法解决问题，内置类型还是浅拷贝，对于自定义类型调用赋值重载,拷贝构造（编译器优化）
				delete[]_start;
			}
			_start = tmp;
			_finsh = _start + size;
			_endofstoage = _start + n;
		}
		void resize(size_t n, const T& val = T()) {
			reserve(n);
			if (n <= size()) {
				_finsh = _start+n;
			}
			else {
				while (n > size())
					*_finsh++ = val;
			}
		}
		void push_back(const T& x) {
			insert(end(), x);
		}
		void pop_back() {
			erase(end() - 1);
		}
		iterator insert(iterator pos, const T& x) {
			assert(pos >= _start && pos <= _finsh);
			if (_finsh == _endofstoage) {
				size_t des = pos - _start;
				reserve(capacity() ? 2 * capacity() : 4);
				pos = _start + des;
			}
			for (iterator cur = _finsh; cur > pos; cur--) {
				*cur = *(cur - 1);
			}
			*pos = x;
			_finsh++;
			return pos;
		}
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finsh);
			for (iterator cur = pos; cur < _finsh-1; cur++) {
				*cur=*(cur+1);
			}
			_finsh--;
			return pos;
		}
		void clear() {
			_finsh = _start;
		}
		void pop_back(const T& x) {
			if (_finsh > _start)
				--_finsh;
		}
		const T& operator [](const size_t pos)const {
			assert(pos < size());
			return *(_start + pos);
		}
		T& operator [](const size_t pos){
			assert(pos < size());
			return *(_start + pos);
		}

	private:
		iterator _start;
		iterator _finsh;
		iterator _endofstoage;
	};
}