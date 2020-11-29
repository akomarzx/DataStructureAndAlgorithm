#pragma once
#include<initializer_list>
class IntArray
{
private:
	int* MemoryLocation;
	size_t capacity;
	size_t length;
	void Swap(int* Value_A, int* Value_B); //Internal Function for LinearSearch improvement
	void ReallocateAndResize();
public:
	IntArray(const IntArray& Source);
	~IntArray();
	IntArray();
	IntArray(size_t Count);//Allocates n Memory for the array  
	IntArray(std::initializer_list<int>Initial_Elements);
	void Print()const;
	void Add(int New_Element);
	int& at(size_t index);//Element Access with bounds Checking
	size_t Size()const;
	void Insert(int Index, int Value);//Insert Element at Index 
	void Delete(int Index);
	int LinearSearch(int Key);//Linear Search Version returns the index if search is successful -1 if search is unsuccessful
	int BinarySearch(int Key)const;//Iterative Version of Binary Search Version returns the index if search is successful -1 if search is unsuccessful
	int Max()const; // Return the Highest Element in the array
	int Min()const; // Return the Lowest Element in the array
	int Sum()const;
	float Average()const;
	int* GetArray()const;
	int Capacity()const;
};