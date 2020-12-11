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

void IntArray::ReallocateAndResize(int Extra)
{
	capacity *= (2 + Extra);
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
	: capacity{ Initial_Elements.size() }, length{ Initial_Elements.size() }
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
	:capacity{ Source.capacity }, length{ Source.length }
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

void IntArray::push_back(int New_Element)
{
	if (length < capacity)
	{
		MemoryLocation[length] = New_Element;
		++length;
	}
	else
	{
		ReallocateAndResize(0);
		push_back(New_Element);
	}
	if (New_Element < MemoryLocation[length - 2])//We have to compare the element with the element before it. if i use the length it will be compare to itself so we have to offset two index to reach the last element before insertion
	{
		IsArraySorted = false;
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
	IsArraySorted = false;
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
			ReallocateAndResize(0);
			Insert(Index, Value);
		}
		IsArraySorted = false;
	
}

bool IntArray::Insert(int Value) // Returns False if the array is not sorted return true if insertion is successful the array is sorted. 
{
	if (IsSorted())
	{
		if (length < capacity)
		{
			for (int x = length; x >= 0; --x)
			{
				if (Value > MemoryLocation[x - 1])
				{
					MemoryLocation[x] = Value;
					++length;
					return true;
				}
				else
				{
					MemoryLocation[x] = MemoryLocation[x - 1];
				}
			}
			return false;
		}
		else
		{
			ReallocateAndResize(0);
			Insert(Value);
		}
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
	IsArraySorted = false;
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

int IntArray::BinarySearch(int Key) 
{
	if (IsSorted())
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
	for (size_t x{ 0 }, y{ length - 1 }; x < length; ++x, --y)
	{
		TempArray[x] = MemoryLocation[y];
	}
	delete[]MemoryLocation;
	MemoryLocation = TempArray;
	TempArray = nullptr;
}

void IntArray::LeftShift()
{
	for (int x{ 0 }; x < length; ++x)
	{
		MemoryLocation[x] = MemoryLocation[x + 1];
	}
	MemoryLocation[length - 1] = 0;
	IsArraySorted = false;
}

void IntArray::RightShift()
{
	for (int x = length - 1; x >= 0; --x)
	{
		MemoryLocation[x] = MemoryLocation[x - 1];
	}
	MemoryLocation[0] = 0;
}

void IntArray::RightRotate()
{
	int temp = MemoryLocation[length - 1];
	for (int x = length - 1; x >= 0; --x)
	{
		MemoryLocation[x] = MemoryLocation[x - 1];
	}
	MemoryLocation[0] = temp;
	IsArraySorted = false;
}

void IntArray::LeftRotate()
{
	int temp = MemoryLocation[0];
	for (int x{ 0 }; x < length; ++x)
	{
		MemoryLocation[x] = MemoryLocation[x + 1];
	}
	MemoryLocation[length - 1] = temp;
	IsArraySorted = false;
}

bool IntArray::IsSorted()
{
	if (!IsArraySorted)
	{
		for (int x{ 0 }; x < length - 1; ++x)
		{
			if (MemoryLocation[x] > MemoryLocation[x + 1])
			{
				return false;
			}
		}
	}
	IsArraySorted = true;
	return true;
}

IntArray::iterator IntArray::begin()const
{
	return MemoryLocation;
}

IntArray::iterator IntArray::end()const
{
	return(MemoryLocation + length);
}

void IntArray::NegativeRotate()
{
	for (size_t OuterLoop{ length - 1 }; OuterLoop > 0; --OuterLoop)
	{
		if (MemoryLocation[OuterLoop] < 0)
		{
			for (int InnerLoop{ 0 }; InnerLoop < OuterLoop; ++InnerLoop)
			{
				if (MemoryLocation[InnerLoop] > 0)
				{
					Swap((MemoryLocation + OuterLoop), (MemoryLocation + InnerLoop));
					break;
				}
			}
		}
	}
}

void IntArray::Merge(const IntArray& OtherArray)
{
	ReallocateAndResize(OtherArray.length);
	for (size_t x{ 0 }; x < OtherArray.length; ++x)
	{
		this->push_back(OtherArray.MemoryLocation[x]);
	}
}
