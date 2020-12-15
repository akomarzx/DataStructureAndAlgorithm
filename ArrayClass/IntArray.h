#pragma once
#include<initializer_list>

class IntArray;

namespace SetOperation
{
	IntArray Union(IntArray& Array1, IntArray& Array2);
	IntArray Intersection(const IntArray& Array1, const IntArray& Array2);
	IntArray Difference(const IntArray& Array1, const IntArray& Array2);
}

class IntArrayIterator
{
private:
	int* Pointer;
public:
	IntArrayIterator(int* m_Ptr)
		: Pointer{ m_Ptr } {}
	IntArrayIterator& operator++()
	{
		++Pointer;
		return *this;
	}
	IntArrayIterator& operator++(int)
	{
		IntArrayIterator iterator = *this;
		++(*this);
		return iterator;
	}
	IntArrayIterator& operator--()
	{
		--Pointer;
		return *this;
	}
	IntArrayIterator& operator--(int)
	{
		IntArrayIterator iterator = *this;
		--(*this);
		return iterator;
	}
	int operator[](int index)
	{
		return *(Pointer + index);
	}
	int operator*()const
	{
		return *Pointer;
	}
	bool operator==(const IntArrayIterator& OtherValue)const
	{
		return (this->Pointer == OtherValue.Pointer);
	}
	bool operator!=(const IntArrayIterator& OtherValue)const
	{
		return !(this->Pointer == OtherValue.Pointer);
	}
};

class IntArray
{
private:
	using iterator = IntArrayIterator;
	friend IntArray SetOperation::Union(IntArray& Array1,IntArray& Array2);
	friend IntArray SetOperation::Intersection(IntArray& Array1, IntArray& Array2);
	friend IntArray SetOperation::Difference(IntArray& Array1,IntArray& Array2);
	mutable int* MemoryLocation;
	size_t capacity;
	size_t length;
	void Swap(int* Value_A, int* Value_B); //Internal Function for LinearSearch improvement
	void ReallocateAndResize(size_t Extra);
	bool IsArraySorted = false;
public:
	IntArray(const IntArray& Source);
	~IntArray();
	IntArray();
	explicit IntArray(size_t Count);//Allocates n Memory for the array
	IntArray(std::initializer_list<int>Initial_Elements);
	void Print()const;
	void push_back(int New_Element);
	int& at(size_t index);//Element Access with bounds Checking
	size_t Size()const;
	void Insert(int Index, int Value);//Insert Element at Index
	bool Insert(int Value); // Returns False if the array is not sorted return true if insertion is successful the array is sorted.
	void Delete(int Index);//Removes The element at chosen index
	int LinearSearch(int Key);//Linear Search Version returns the index if search is successful -1 if search is unsuccessful
	int BinarySearch(int Key);//NOTE:	Only use for Sorted Array.iterative Version of Binary Search Version returns the index if search is successful -1 if search is unsuccessful
	int Max()const; // Return the Highest Element in the array
	int Min()const; // Return the Lowest Element in the array
	int Sum()const;
	float Average()const;
	int* GetArray()const;
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
	void Merge(const IntArray& OtherArray);
	bool MergeAndSort(IntArray& OtherArray);// Merge Two Sorted Arrays Returns false if one of the array is not sorted and true if array is merged successfully.
};