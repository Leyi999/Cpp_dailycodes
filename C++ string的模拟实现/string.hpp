#pragma once
#include<string.h>
#include<assert.h>
#include<iostream>
class String {
public:
	String(const char* str = "")
		: _size(strlen(str))
		, _capacity(_size)
		, _str(new char[_capacity + 1])
	{
		strcpy(_str, str);
	}
	String(const String& str)
		:_size(strlen(str._str))
		, _capacity(_size)
		, _str(new char[_capacity + 1])
	{
		strcpy(_str, str._str);
	}
	~String() 
	{
		_capacity = _size = 0;
		delete[]_str;
		_str = nullptr;
	}
	const char& operator[](size_t pos)const {
		assert(pos < _size + 1);
		return *(_str + pos);
	}
	char& operator[](size_t pos) {
		assert(pos < _size+1);
		return *(_str + pos);
	}
	String& operator=(const String& str) {
		if (&str != this) {
			char* tmp = new char[str._capacity + 1];
			strcpy(tmp, str._str);
			delete[]_str;
			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}
			return*this;
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
		if (_size == _capacity) {
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		_str[_size++] = ch;
		_str[_size] = 0;
	}
	void append(const char* str) {
		size_t len = strlen(str) + _size;
		reserve(len);
		strcat(_str+_size, str);
		_size = len;
	}
	void append(const String& str) {
		reserve(str._size + _size);
		strcat(_str + _size, str._str);
		_size += str._size;
	}
	String& operator +=(const char ch) {
		pushback(ch);
		return *this;
	}
	String& operator +=(const String& str) {
		append(str);
		return *this;
	}

private:
	size_t _size;
	size_t _capacity;
	char* _str;
};
	bool operator >(const String& str1,const String& str2) {
		return strcmp(str1.c_str(), str2.c_str()) > 0;
	}
	bool operator <(const String& str1,const String& str2) {
		return strcmp(str1.c_str(), str2.c_str()) < 0;
	}
	bool operator ==(const String& str1,const String& str2) {
		return strcmp(str1.c_str(), str2.c_str()) == 0;
	}
	bool operator >=(const String& str1,const String& str2) {
		return !(str1 < str2);
	}
	bool operator <=(const String& str1,const String& str2) {
		return !(str1 > str2);
	}