#pragma once
#include<initializer_list>
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
	int* MemoryLocation;
	size_t capacity;
	size_t length;
	void Swap(int* Value_A, int* Value_B); //Internal Function for LinearSearch improvement
	void ReallocateAndResize();
public:
	IntArray(const IntArray& Source);
	~IntArray();
	IntArray();
	explicit IntArray(size_t Count);//Allocates n Memory for the array  
	IntArray(std::initializer_list<int>Initial_Elements);
	void Print()const;
	void Add(int New_Element);
	int& at(size_t index);//Element Access with bounds Checking
	size_t Size()const;
	void Insert(int Index, int Value);//Insert Element at Index 
	void Delete(int Index);
	int LinearSearch(int Key);//Linear Search Version returns the index if search is successful -1 if search is unsuccessful
	int BinarySearch(int Key)const;//NOTE:	Only use for Sorted Array.terative Version of Binary Search Version returns the index if search is successful -1 if search is unsuccessful
	int Max()const; // Return the Highest Element in the array
	int Min()const; // Return the Lowest Element in the array
	int Sum()const;
	float Average()const;
	int* GetArray()const;
	int Capacity()const;
	iterator begin();
	iterator end();
};