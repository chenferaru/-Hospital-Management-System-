#pragma once
#include <fstream>
#include <iostream>


using namespace std;

template<class T>
class Array
{
public:

	Array();
	Array(const Array& other);
	~Array();

public:

	const Array& operator=(const Array& other);
	void push_back(const T& member);
	int size();
	int capacity();
	void reserve(int newCapacity);

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr.size(); i++)
			os << arr.m_arr[i] << endl;
		os << endl;
		return os;
	}
	T& operator[](int index)
	{
		return m_arr[index];
	}

private:
	int m_size;
	int m_capacity;
	T* m_arr;

};

template<class T>
Array<T>::Array()
{
	m_arr = nullptr;
	m_size = m_capacity = 0;
}

template<class T>
Array<T>::Array(const Array& other)
{
	*this = other;
}

template<class T>
Array<T>::~Array()
{
	delete[]m_arr;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] m_arr;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_arr = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
			m_arr[i] = other.m_arr[i];
	}
	return *this;
}

template<class T>
int Array<T>::size()
{
	return m_size;
}

template<class T>
int Array<T>::capacity()
{
	return m_capacity;
}

template<class T>
void Array<T>::reserve(int newCapacity)
{
	T* tmpArr;
	tmpArr = new T[newCapacity];
	for (int i = 0; i < m_size; i++)
	{
		tmpArr[i] = m_arr[i];
	}
	delete[]m_arr;
	m_arr = tmpArr;
	m_capacity = newCapacity;
}

template<class T>
void Array<T>::push_back(const T& member)
{
	if (m_size == m_capacity)
	{
		++m_capacity;
		reserve(m_capacity);
	}
	m_arr[m_size++] = member;
}