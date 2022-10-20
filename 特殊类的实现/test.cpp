//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//template<class T>
//class shared_ptr {
//public:
//	shared_ptr() = default;
//	shared_ptr(T* ptr) 
//		:_ptr(ptr), _count(new int{1}) {
//		;
//	}
//	~shared_ptr() {
//		if (!-- * _count) {
//			delete _ptr;
//			printf("%p : 释放资源\n",this);
//		}
//	}
//	shared_ptr(shared_ptr& ptr)
//	:_ptr(ptr._ptr),_count(ptr._count)
//	{
//		(*_count)++;
//	}
//	shared_ptr& operator=(shared_ptr& ptr) {
//		if(_ptr)
//			if (!-- * _count)
//				delete _ptr;
//		_ptr = ptr._ptr;
//		_count = ptr._count;
//		*_count += 1;
//		return *this;
//	}
//	T& operator *() {
//		return *_ptr;
//	}
//	T* operator ->() {
//		return &*_ptr;
//	}
//	shared_ptr& operator++() {
//		++_ptr;
//		return *this;
//	}
//	shared_ptr operator++(int) {
//		shared_ptr ret(*this);
//		_ptr++;
//		return ret;
//	}
//	//-- --（int）类似
//
//private:
//	T* _ptr;
//	int* _count;
//};
//void* my_memcpy(void* des, const void* src, size_t size) {
//	char* d = (char*)des;
//	const char *s = (const char*)src;
//	while (size--) 
//		*d++ = *s++;
//	return des;
//}
//void* my_memmove(void* des, const void* src, size_t size) {
//	char* d_end = (char*)des+size;
//	const char* s_end = (char*)src+size;
//	while (size--)
//		*(d_end-- - 1) = *(s_end-- - 1);
//	return des;
//}
//
//int main() {
//	int arr1[10];
//	int i = 1;
//	for (auto& e : arr1) {
//		e = i++;
//		std::cout << e<<' ';
//	}
//	std::cout << std::endl;
//	int arr2[10];
//	for (auto& e : arr2) {
//		e = --i;
//		std::cout << e<<' ';
//	}
//	std::cout << std::endl;
//	//memmove(arr1, arr2, sizeof(arr1));
//	memmove(arr1+4, arr1+1, 5*sizeof(int));
//	for (auto e : arr1) {
//		std::cout << e << ' ';
//	}
//	std::cout << std::endl;
//	shared_ptr<int>sp1(new int{ 3 });
//	std::cout << &sp1 << std::endl;
//	shared_ptr<int>sp2;
//	*sp1 = 4;
//	sp2 = sp1;
//	std::cout << *sp2 << std::endl;
//	shared_ptr<int>sp3(sp2);
//	*sp1 = 5;
//	std::cout << *sp3 << std::endl;
//	return 0;
//}