#include <iostream>
using namespace std;
#include <vector>

// 오늘의 주제 : vector

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()
	{
		// 전위인 경우에는 중첩이 가능함
		// 증가 후에 대입
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		// 후위인 경우에는 중첩이 불가능함
		// 복사하고 증가시킴
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator& operator--()
	{
		// 전위인 경우에는 중첩이 가능함
		// 증가 후에 대입
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		// 후위인 경우에는 중첩이 불가능함
		// 복사하고 증가시킴
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return _ptr != right._ptr; // return !(*this == right);도 가능
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
};

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	// [         ]
	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);

			// 0이라면? 1이라면? -> 변동 X
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = val;

		// 데이터 개수 증가
		_size++;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;

		T* newData = new T[_capacity];

		// 이전 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// 이전 데이터 삭제
		if (_data)
			delete[] _data;

		// 교체
		_data = newData;
	}

	T& operator[](const int pos) { return _data[pos]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }

private:
	T* _data;
	int _size;
	int _capacity;
};

int main()
{
	Vector<int> v;

	v.reserve(100);

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "---------------------------" << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}