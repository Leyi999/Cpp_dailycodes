#pragma once
//��ȡ ʵ��һ����ȡ�� ������������ػ� ����ͬ���ͣ����ֱ�Ӵ���ȡ�������ý��
//ʹ����ȡ��Ͳ��ð�Reverse_Iterator copy�����ػ����� 
template<typename Iterator>
struct Iterator_traits {//�Զ������͵�iterator��const_iterator�������������Բ���Ҫ�ֿ���ȡ���ػ���
	typedef typename Iterator::Ref				Ref;
	typedef typename Iterator::Ptr				Ptr;
};
template<typename T>//ԭ��ָ��� const_iterator����cosnt iterator ����Ҫ�ֿ���ȡ���ػ���
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