#pragma once
#include<string.h>
#include<assert.h>
#include<iostream>
using namespace std;
class String {
public:
	typedef char* iterator;
	typedef const char* const_iterator;

	const_iterator begin()const {
		return _str;
	}
	iterator begin() {
		return _str;
	}
	const_iterator end()const {
		return _str + _size;
	}
	iterator end() {
		return _str + _size;
	}
	String(const char* str = "")
		: _size(strlen(str))
		, _capacity(_size)
		, _str(new char[_capacity + 1])
	{
		strcpy(_str, str);
	}

	~String()
	{
		_capacity = _size = 0;
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}
	////传统写法
	//String(const String& str)
	//	:_size(strlen(str._str))
	//	, _capacity(_size)
	//	, _str(new char[_capacity + 1])
	//{
	//	strcpy(_str, str._str);
	//}
	//现代写法
	String(const String& str)
	{
		String tmp(str._str);
		swap(tmp);
	}
	void swap(String& str) {
		std::swap(_str, str._str);
		std::swap(_size, str._size);
		std::swap(_capacity, str._capacity);
	}
	////传统写法
	//String& operator=(const String& str) {
	//	if (&str != this) {
	//		char* tmp = new char[str._capacity + 1];
	//		strcpy(tmp, str._str);
	//		if(_str)
	//			delete[]_str;
	//		_str = tmp;
	//		_size = str._size;
	//		_capacity = str._capacity;
	//	}
	//		return*this;
	//}
	//现代写法
	String& operator=( String str) {
		swap(str);
		return*this;
	}

	const char& operator[](size_t pos)const {
		assert(pos < _size + 1);
		return *(_str + pos);
	}
	char& operator[](size_t pos) {
		assert(pos < _size+1);
		return *(_str + pos);
	}
	const char* c_str()const {
		return _str;
	}
	char* c_str() {
		return _str;
	}
	size_t size() const{
		return _size;
	}
	size_t capacity() const{
		return _capacity;
	}
	void reserve(size_t n) {
		if (n <= _capacity)
			return;
		char* tmp = new char[(_capacity = n) + 1];
		strcpy(tmp, _str);
		if(_str)
			delete[]_str;
		_str = tmp;
	}
	void resize(size_t n, const char ch= 0) {
		if (n <= _size) {
			_size = n;
			_str[_size] = 0;
			return;
		}
		reserve(n);
		while (_size < n) {
			_str[_size++] = ch;
		}
		_str[_size] = 0;
	}
	void pushback(const char ch) {
		insert(_size, ch);
	}
	void append(const char* str) {
		insert(_size, str);
	}
	void append(const String& str) {
		insert(_size, str._str);
	}
	String& operator +=(const char ch) {
		pushback(ch);
		return *this;
	}
	String& operator +=(const String& str) {
		append(str);
		return *this;
	}
	String& insert(size_t pos,const char ch) {
		assert(pos <= _size);
		if(_capacity<_size+1)
		reserve(_capacity == 0 ? 4 : 2 * _capacity);
		//memmove(_str + pos + 1, _str + pos, _size - pos);
		
		for (size_t cur = _size; cur > pos; cur--) {
			_str[cur] = _str[cur - 1];
		}
		_str[pos] = ch;
		_str[++_size] = 0;
		return *this;
	};
	String& insert(size_t pos, const char* str) {
		assert(pos <= _size);
		size_t len = strlen(str);
		reserve(len + _size);
		//memmove(_str + pos + len, _str + pos,_size-pos);
		//memmove(_str + pos, str, len);
		for (size_t cur = _size+len-1; cur > pos+len-1; cur--) {
			_str[cur] = _str[cur - len];
		}
		for (size_t i = 0; i <  len; i++) {
			_str[pos+i] = str[i];
		}
		_str[_size += len] = 0;
		return *this;
	}
	String& erase(size_t pos = 0, size_t len = npos) {
		assert(pos <= _size);
		if (len == npos || pos + len >= _size) {
			_size=_str[pos] = 0;
			return *this;
		}
		for (size_t cur = pos + len; cur < _size; cur++,pos++) {
			_str[pos] = _str[cur];
		}
		_str[_size = pos] = 0;
		return *this;
	}
	size_t find(const char ch,size_t pos=0)const {
		for (size_t i = 0; i < _size; i++) 
			if (_str[i] == ch)
				return i;
		return npos;
	}
	size_t find(const char* str, size_t pos = 0)const {
		const char* pc = strstr(_str+pos, str);
		return pc ? pc - _str : npos;
	}

private:
	size_t _size;
	size_t _capacity;
	char* _str;
	const static size_t npos ;
}; 
const size_t	String::npos = -1;
ostream& operator <<(ostream& out, const String& str) {
	for (auto e : str)
		out << e;
	return out;
}
istream& operator >>(istream& in, String& str) {
	str.erase();
	
	char buff[128];
	memset(buff, 0, 128);

	size_t i = 0;
	do {
		buff[i++] = in.get();
		if (i == 127) {
			str += buff;
			memset(buff, 0, 128);
			i = 0;
		}
	} while (buff[i-1] != ' ' && buff[i-1] != '\n');
	str += buff;
	return in;
}
bool operator >(const String& str1, const String& str2) {
	return strcmp(str1.c_str(), str2.c_str()) > 0;
}
bool operator <(const String& str1, const String& str2) {
	return strcmp(str1.c_str(), str2.c_str()) < 0;
}
bool operator ==(const String& str1, const String& str2) {
	return strcmp(str1.c_str(), str2.c_str()) == 0;
}
bool operator >=(const String& str1, const String& str2) {
	return !(str1 < str2);
}
bool operator <=(const String& str1, const String& str2) {
	return !(str1 > str2);
}