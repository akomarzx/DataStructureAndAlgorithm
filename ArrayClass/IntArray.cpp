#include "IntArray.h"
#include<initializer_list>
#include<iostream>
#include<list>
void IntArray::Swap(int* Value_A, int* Value_B)
{
	int Temp = *Value_A;
	*Value_A = *Value_B;
	*Value_B = Temp;
}

void IntArray::ReallocateAndResize()
{
	capacity *= 2;
	int* TempArray = new int[capacity];
	for (int x{ 0 }; x < length; ++x)
	{
		TempArray[x] = MemoryLocation[x];
	}
	delete[]MemoryLocation;
	MemoryLocation = TempArray;
	TempArray = nullptr;
}
IntArray::IntArray(size_t Count)//Allocates n Memory for the array  
	:capacity{ Count }, length{ 0 }
{
	MemoryLocation = new int[capacity];
}

IntArray::IntArray()//Default Constructor allocates 10 memory space.
	: capacity{ 10 }, length{ 0 }
{
	MemoryLocation = new int[capacity];
}
IntArray::IntArray(std::initializer_list<int>Initial_Elements)
	:capacity{ Initial_Elements.size() }, length{ Initial_Elements.size() }
{
	MemoryLocation = new int[Initial_Elements.size()];
	int CurrentIndex = 0;
	for (auto Element : Initial_Elements)
	{
		MemoryLocation[CurrentIndex] = Element;
		++CurrentIndex;
	}
}

IntArray::IntArray(const IntArray& Source)
	:capacity{Source.capacity} , length{Source.length}
{
	MemoryLocation = new int[capacity];
	for (int x{ 0 }; x < length; ++x)
	{
		this->MemoryLocation[x] = Source.MemoryLocation[x];
	}
}

IntArray::~IntArray()
{
	delete[] MemoryLocation;
}

void IntArray::Print() const
{
	std::cout << '{';
	for (size_t Index{ 0 }; Index < length; ++Index)
	{
		std::cout << MemoryLocation[Index] << ' ';
	}
	std::cout << '}' << '\n';
}

void IntArray::Add(int New_Element)
{
	if (length < capacity)
	{
		MemoryLocation[length] = New_Element;
		++length;
	}
	else
	{
		ReallocateAndResize();
		Add(New_Element);
	}
}

int& IntArray::at(size_t index) //Element Access with bounds Checking
{
	if (index < length && index >= 0)
	{
		return (MemoryLocation[index]);
	}
	else
	{
		throw "Testing";
	}
}

size_t IntArray::Size() const
{
	return length;
}

void IntArray::Insert(int Index, int Value)
{
	if (Index >= 0 && Index < length && ++length <= capacity)
	{
		for (size_t x = length; x > Index; --x)
		{
			MemoryLocation[x] = MemoryLocation[x - 1];
		}
		MemoryLocation[Index] = Value;
	}
	else
	{
		--length;
		ReallocateAndResize();
		Insert(Index, Value);
	}
}

void IntArray::Delete(int Index)
{
	if (Index >= 0 && Index < length)
	{
		for (int CurrentIndex{ Index }; CurrentIndex < length; ++CurrentIndex)
		{
			MemoryLocation[CurrentIndex] = MemoryLocation[CurrentIndex + 1];
		}
		MemoryLocation[length - 1] = 0;
		--length;
	}
	else
	{
		throw 1;
	}
}

int IntArray::LinearSearch(int Key)
{
	if (length <= 0)
	{
		return -1;
	}
	else
	{
		for (int x{ 0 }; x < length; ++x)
		{
			if (Key == MemoryLocation[x])
			{
				Swap((MemoryLocation + x), MemoryLocation);
				return MemoryLocation[0];
			}
		}
		return -1;
	}
}

int IntArray::BinarySearch(int Key) const
{
	if (length <= 0)
	{
		return -1;
	}
	size_t low = 0, high = length - 1, middle;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (MemoryLocation[middle] == Key)
		{
			return middle;
		}
		else if (MemoryLocation[middle] > Key)
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	return -1;
}

int IntArray::Max() const 
{
	int Max = MemoryLocation[0];
	for (int x{ 0 }; x < length; ++x)
	{
		if (MemoryLocation[x] > Max)
		{
			Max = MemoryLocation[x];
		}
	}
	return Max;
}

int IntArray::Min() const 
{
	int Min = MemoryLocation[0];
	for (int x{ 0 }; x < length; ++x)
	{
		if (MemoryLocation[x] < Min)
		{
			Min = MemoryLocation[x];
		}
	}
	return Min;
}

int IntArray::Sum() const
{
	int sum = MemoryLocation[0];
	for (int x{ 1 }; x < length; ++x)
	{
		sum += MemoryLocation[x];
	}
	return sum;
}

float IntArray::Average() const
{
	return Sum() / static_cast<float>(length);
}

int* IntArray::GetArray() const
{
	return MemoryLocation;
}

int IntArray::Capacity() const
{
	return capacity;
}

void IntArray::Reverse()
{
	int* TempArray = new int[capacity];
	for (size_t x{ 0 }, y{ length - 1 } ; x < length ; ++x , --y)
	{
		TempArray[x] = MemoryLocation[y];
	}
	delete[]MemoryLocation;
	MemoryLocation = TempArray;
	TempArray = nullptr;
}

IntArray::iterator IntArray::begin()
{
	return MemoryLocation;
}

IntArray::iterator IntArray::end()
{
	return(MemoryLocation + length);
}
