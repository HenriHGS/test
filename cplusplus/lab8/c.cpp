#include <iostream>
#include <assert.h>
#include <iomanip>
#include <cmath>
#include <cstdio>
template <class T>
class Array {
private:
	T* list;
	int size;
public:
	Array(int sz = 50);
	Array(const Array<T>& a);
	~Array();
	Array<T>& operator = (const Array<T>& rhs);
	T& operator[] (int i);
	const T& operator[] (int i) const;
	operator T* ();
	operator const T* () const;
	int getSize() const;
	void resize(int sz);
                T* get();
};
template <class T>
 T* Array<T>::get() {
	return this->list;
}



template <class T>
Array<T>::Array(int sz) {
	assert(sz > 0);
	size = sz;
	list = new T[size];
}

template <class T>
Array<T>::~Array() {
	delete [] list;
}

template <class T>
Array<T>::Array(const Array<T> &a) {
	size = a.size;
	list = new T[size];
	for (int i = 0; i < size; i ++)
		list[i] = a.list[i];
}

template <class T>
Array<T>& Array<T>::operator =(const Array<T> &rhs) {
	if (&rhs != this) {
		if (size != rhs.size) {
			delete []list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size ; i ++)
			list[i] = rhs.list[i];
	}
	return *this;
}

template <class T>
T& Array<T>::operator [](int i) {
	assert(i >=0 && i < size);
	return list[i];
}

template <class T>
const T& Array<T>::operator [](int i) const {
	assert(i >=0 && i < size);
	return list[i];
}

template <class T>
Array<T>::operator T *() {
	return list;
}

template <class T>
Array<T>::operator const T *() const {
	return list ;
}

template <class T>
int Array<T>::getSize() const {
	return size;
}

template <class T>
void Array<T>::resize(int sz) {
	assert(sz >= 0);
	if (sz == size)
		return;
	T* newList = new T[sz];
	int n = (sz < size) ? sz : size;
	for (int i = 0; i < n; i ++)
		newList[i] = list[i];
	delete []list;
	list = newList;
	size = sz;
}

using namespace std;
int main() {
	Array<int> a(10);	// 用来存放质数的数组，初始状态有10个元素。
	int n, count = 0;
	cout << "Enter a value >= 2 as upper limit for prime numbers: ";
	cin >> n;
	for (int i = 2; i <= n; i++) {
		bool isPrime = true;
		for (int j = 0; j < count; j++)
			if (i % a[j] == 0) {	//若i被a[j]整除，说明i不是质数
				isPrime = false; break;
			}
		if (isPrime) {
			if (count == a.getSize()) a.resize(count * 2);
			a[count++] = i;
		}
	}
	for (int i = 0; i < count; i++)	cout << setw(8) << a[i];
	cout << endl;
	return 0;
}
