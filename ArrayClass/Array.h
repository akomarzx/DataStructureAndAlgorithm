#pragma once
#include<initializer_list>

template<class T>
class My_Iterator
{
private:
	T* Pointer;
public:
	My_Iterator(int* m_Ptr)
		: Pointer{ m_Ptr } {}
	My_Iterator& operator++()
	{
		++Pointer;
		return *this;
	}
	My_Iterator& operator++(int)
	{
		My_Iterator iterator = *this;
		++(*this);
		return iterator;
	}
	My_Iterator& operator--()
	{
		--Pointer;
		return *this;
	}
	My_Iterator& operator--(int)
	{
		My_Iterator iterator = *this;
		--(*this);
		return iterator;
	}
	T operator[](int index)
	{
		return *(Pointer + index);
	}
	T operator*()const
	{
		return *Pointer;
	}
	bool operator==(const My_Iterator& OtherValue)const
	{
		return (this->Pointer == OtherValue.Pointer);
	}
	bool operator!=(const My_Iterator& OtherValue)const
	{
		return !(this->Pointer == OtherValue.Pointer);
	}
};
template<class T>
class Array
{
private:
	using iterator = My_Iterator;
	T* MemoryLocation;
	size_t capacity;
	size_t length;
	void Swap(int* Value_A, int* Value_B); //Internal Function for LinearSearch improvement
	void ReallocateAndResize(size_t Extra);
	bool IsArraySorted = false;
public:
	Array(const Array& Source);
	~Array();
	Array();
	explicit Array(size_t Count);//Allocates n Memory for the array
	Array(std::initializer_list<T>Initial_Elements);
	void Print()const;
	void push_back(T New_Element);
	int& at(size_t index);//Element Access with bounds Checking
	size_t Size()const;
	void Insert(int Index, T Value);//Insert Element at Index
	bool Insert(T Value); // Returns False if the array is not sorted return true if insertion is successful the array is sorted.
	void Delete(size_t Index);//Removes The element at chosen index
	int LinearSearch(T Key);//Linear Search Version returns the index if search is successful -1 if search is unsuccessful
	int BinarySearch(T Key);//NOTE:	Only use for Sorted Array.iterative Version of Binary Search Version returns the index if search is successful -1 if search is unsuccessful
	T Max()const; // Return the Highest Element in the array
	T Min()const; // Return the Lowest Element in the array
	T* GetArray()const;
	int Capacity()const;
	void Reverse();
	void LeftShift();
	void RightShift();
	void RightRotate();
	void LeftRotate();
	bool IsSorted();
	iterator begin()const;
	iterator end()const;
	void NegativeRotate();
	void Merge(const Array<T>& OtherArray);
	bool MergeAndSort(Array<T>& OtherArray);// Merge Two Sorted Arrays Returns false if one of the array is not sorted and true if array is merged successfully.
	static Array Union(Array& Array1, Array& Array2);
	static Array Intersection(Array& Array1, Array& Array2);
	static Array Difference(Array& Array1, Array& Array2);
};