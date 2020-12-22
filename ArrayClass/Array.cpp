#include "Array.h"
#include<initializer_list>
#include<iostream>
#include<list>
template<typename T>
void Array<T>::Swap(T* Value_A, T* Value_B)
{
	int Temp = *Value_A;
	*Value_A = *Value_B;
	*Value_B = Temp;
}
template<typename T>
void Array<T>::ReallocateAndResize()
{
	capacity *= (2 + Extra);
	T* TempArray = new T[capacity];
	for (int x{ 0 }; x < length; ++x)
	{
		TempArray[x] = MemoryLocation[x];
	}
	delete[]MemoryLocation;
	MemoryLocation = TempArray;
	TempArray = nullptr;
}
template<typename T>
Array<T>::Array(size_t Count)//Allocates n Memory for the array
	:capacity{ Count }, length{ 0 }
{
	MemoryLocation = new T[capacity];
}

Array::Array()//Default Constructor allocates 10 memory space.
	: capacity{ 10 }, length{ 0 }
{
	MemoryLocation = new int[capacity];
}
Array::Array(std::initializer_list<int>Initial_Elements)
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

Array::Array(const Array& Source)
	:capacity{ Source.capacity }, length{ Source.length }
{
	MemoryLocation = new int[capacity];
	for (int x{ 0 }; x < length; ++x)
	{
		this->MemoryLocation[x] = Source.MemoryLocation[x];
	}
}

Array::~Array()
{
	delete[] MemoryLocation;
}

void Array::Print() const
{
	std::cout << '{';
	for (size_t Index{ 0 }; Index < length; ++Index)
	{
		std::cout << MemoryLocation[Index] << ' ';
	}
	std::cout << '}' << '\n';
}

template<class T> void Array::push_back(T New_Element)
{
	if (length < capacity)
	{
		MemoryLocation[length] = New_Element;
		++length;
	}
	else
	{
		ReallocateAndResize();
		push_back(New_Element);
	}
	if (New_Element < MemoryLocation[length - 2])//We have to compare the element with the element before it. if i use the length it will be compare to itself so we have to offset two index to reach the last element before insertion
	{
		IsArraySorted = false;
	}
}

int& Array::at(size_t index) //Element Access with bounds Checking
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

size_t Array::Size() const
{
	return length;
}

void Array::Insert(int Index, int Value)
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
	IsArraySorted = false;
}

bool Array::Insert(int Value) // Returns False if the array is not sorted return true if insertion is successful the array is sorted.
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
			ReallocateAndResize();
			Insert(Value);
		}
	}
}

void Array::Delete(int Index)
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

int Array::LinearSearch(int Key)
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

int Array::BinarySearch(int Key)
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

int Array::Max() const
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

int Array::Min() const
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

int* Array::GetArray() const
{
	return MemoryLocation;
}

int Array::Capacity() const
{
	return capacity;
}

void Array::Reverse()
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

void Array::LeftShift()
{
	for (int x{ 0 }; x < length; ++x)
	{
		MemoryLocation[x] = MemoryLocation[x + 1];
	}
	MemoryLocation[length - 1] = 0;
	IsArraySorted = false;
}

void Array::RightShift()
{
	for (int x = length - 1; x >= 0; --x)
	{
		MemoryLocation[x] = MemoryLocation[x - 1];
	}
	MemoryLocation[0] = 0;
}

void Array::RightRotate()
{
	int temp = MemoryLocation[length - 1];
	for (int x = length - 1; x >= 0; --x)
	{
		MemoryLocation[x] = MemoryLocation[x - 1];
	}
	MemoryLocation[0] = temp;
	IsArraySorted = false;
}

void Array::LeftRotate()
{
	int temp = MemoryLocation[0];
	for (int x{ 0 }; x < length; ++x)
	{
		MemoryLocation[x] = MemoryLocation[x + 1];
	}
	MemoryLocation[length - 1] = temp;
	IsArraySorted = false;
}

bool Array::IsSorted()
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

Array::iterator Array::begin()const
{
	return MemoryLocation;
}

Array::iterator Array::end()const
{
	return(MemoryLocation + length);
}

void Array::NegativeRotate()
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

void Array::Merge(const Array& OtherArray)
{
	//Todo Redo the function to make life easier
}

bool Array::MergeAndSort(Array& OtherArray)
{
	if (this->IsSorted() && OtherArray.IsSorted())
	{
		int arr1 = 0, arr2 = 0, arr3 = 0;
		int TempArrayCap = length + OtherArray.length;
		int* TempArray = new int[TempArrayCap];
		while (arr1 < length && arr2 < OtherArray.length)
		{
			if (MemoryLocation[arr1] < OtherArray.MemoryLocation[arr2])
			{
				TempArray[arr3] = MemoryLocation[arr1];
				++arr1;
			}
			else
			{
				TempArray[arr3] = OtherArray.MemoryLocation[arr2];
				++arr2;

			}
			++arr3;
		}
		for (; arr1 < length; ++arr1)
		{
			TempArray[arr3] = MemoryLocation[arr1];
			++arr3;
		}
		for (; arr2 < OtherArray.length; ++arr2)
		{
			TempArray[arr3] = OtherArray.MemoryLocation[arr2];
			++arr3;
		}
		delete[]MemoryLocation;
		MemoryLocation = TempArray;
		TempArray = nullptr;
		length = TempArrayCap;
		return true;
	}
	else
	{
		return false;
	}
}

Array Array::Union(Array& Array1, Array& Array2)
{
	int arr1 = 0, arr2 = 0, arr3 = 0;
	Array TempArray;
	while (arr1 < Array1.length && arr2 < Array2.length)
	{
		if (Array1.at(arr1) == Array2.at(arr2))
		{
			++arr1;
			++arr2;
		}
		else if (Array1.at(arr1) < Array2.at(arr2))
		{	
			TempArray.push_back(Array1.at(arr1));
			++arr1;
		}
		else
		{
			TempArray.push_back(Array2.at(arr2));
			++arr2;
		}
	}
	for (; arr1 < Array1.length; ++arr1)
	{
		TempArray.push_back(Array1.at(arr1));
	}
	for (; arr2 <Array2.length; ++arr2)
	{
		TempArray.push_back(Array2.at(arr2));
	}
	return TempArray;
}

Array Array::Intersection(Array& Array1,  Array& Array2)
{
	int arr1 = 0, arr2 = 0, arr3 = 0;
	Array TempArray;
	while (arr1 < Array1.length && arr2 < Array2.length)
	{
		if (Array1.at(arr1) == Array2.at(arr2))
		{
			TempArray.push_back(Array1.at(arr1));
			++arr1;
			++arr2;
		}
		else if (Array1.at(arr1) < Array2.at(arr2))
		{
			++arr1;
		}
		else
		{
			++arr2;
		}
	}
	for (; arr1 < Array1.length; ++arr1)
	{
		if (Array1.at(arr1) == Array2.at(arr2))
		{
			TempArray.push_back(Array1.at(arr1));
		}
	}
	for (; arr2 < Array2.length; ++arr2)
	{
		if (Array1.at(arr1) == Array2.at(arr2))
		{
			TempArray.push_back(Array2.at(arr2));
		}
	}
	return TempArray;
}

Array Array::Difference(Array& Array1, Array& Array2)
{
	Array Temp;
	Temp.Merge(Array1);
	return Temp;
}
