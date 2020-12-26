#pragma once
#include<initializer_list>
#include<iostream>
#include<list>
template<class T>
class My_Iterator
{
private:
	T* Pointer;
public:
	My_Iterator<T>(T* m_Ptr)
		: Pointer{ m_Ptr } {}
	My_Iterator<T>& operator++()
	{
		++Pointer;
		return *this;
	}
	My_Iterator<T>& operator++(int)
	{
		My_Iterator<T> iterator = *this;
		++(*this);
		return iterator;
	}
	My_Iterator<T>& operator--()
	{
		--Pointer;
		return *this;
	}
	My_Iterator<T>& operator--(int)
	{
		My_Iterator iterator = *this;
		--(*this);
		return iterator;
	}
	T operator[](int index)
	{
		return *(Pointer + index);
	}
	const T operator*()const
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
	T* MemoryLocation;
	size_t capacity;
	size_t length;
	void Swap(T* Value_A, T* Value_B); //Internal Function for LinearSearch improvement
	void ReallocateAndResize();
	bool IsArraySorted = false;
public:
	Array<T>(const Array<T>& Source);
	~Array<T>();
	Array<T>();
	explicit Array<T>(size_t Count);//Allocates n Memory for the array
	explicit Array<T>(std::initializer_list<T>Initial_Elements);
	void Print()const;
	void push_back(T& New_Element);
	void emplace_back(T&& New_Element);
	T& at(size_t index);//Element Access with bounds Checking
	size_t Size()const;
	void Insert(int Index, T Value);//Insert Element at Index
	bool Insert(T Value); // Returns False if the array is not sorted return true if insertion is successful the array is sorted.
	void Delete(size_t Index);//Removes The element at chosen index
	My_Iterator<T> LinearSearch(T Key);//Returns an iterator if the element is found return end if not found!
	My_Iterator<T> BinarySearch(T Key);//NOTE:	Only use for Sorted Array.iterative Version of Binary Search Version returns the index if search is successful -1 if search is unsuccessful
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
	My_Iterator<T> begin()const;
	My_Iterator<T> end()const;
	void NegativeRotate();
	void Merge(const Array<T>& OtherArray);
	bool MergeAndSort(Array<T>& OtherArray);// Merge Two Sorted Arrays Returns false if one of the array is not sorted and true if array is merged successfully.
	static Array<T> Union(Array<T>& Array1, Array<T>& Array2);
	static Array<T> Intersection(Array<T>& Array1, Array<T>& Array2);
	static Array<T> Difference(Array<T>& Array1, Array<T>& Array2);
};

template<class T>
void Array<T>::emplace_back(T&& New_Element)
{
	if (length < capacity)
	{
		MemoryLocation[length] = std::move(New_Element);
		++length;
	}
	else
	{
		ReallocateAndResize();
		emplace_back(std::move(New_Element));
	}
}

template<typename T>
void Array<T>::Swap(T* Value_A, T* Value_B)
{
	T Temp = *Value_A;
	*Value_A = *Value_B;
	*Value_B = Temp;
}
template<typename T>
void Array<T>::ReallocateAndResize()
{
	capacity *= 2;
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
template<typename T>
Array<T>::Array()//Default Constructor allocates 10 memory space.
	: capacity{ 10 }, length{ 0 }
{
	MemoryLocation = new T[capacity];
}
template<typename T>
Array<T>::Array(std::initializer_list<T>Initial_Elements)
	: capacity{ Initial_Elements.size() }, length{ Initial_Elements.size() }
{
	MemoryLocation = new T[Initial_Elements.size()];
	int CurrentIndex = 0;
	for (auto& Element : Initial_Elements)
	{
		MemoryLocation[CurrentIndex] = Element;
		++CurrentIndex;
	}
}
template<typename T>
Array<T>::Array(const Array<T>& Source)
	:capacity{ Source.capacity }, length{ Source.length }
{
	MemoryLocation = new T[capacity];
	for (int x{ 0 }; x < length; ++x)
	{
		this->MemoryLocation[x] = Source.MemoryLocation[x];
	}
}
template<typename T>
Array<T>::~Array()
{
	delete[] MemoryLocation;
}
template<typename T>
void Array<T>::Print() const
{
	std::cout << '{';
	for (size_t Index{ 0 }; Index < length; ++Index)
	{
		std::cout << MemoryLocation[Index] << ' ';
	}
	std::cout << '}' << '\n';
}

template<class T>
void Array<T>::push_back(T& New_Element)
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
}
template<typename T>
T& Array<T>::at(size_t index) //Element Access with bounds Checking
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
template<typename T>
size_t Array<T>::Size() const
{
	return length;
}
template<typename T>
void Array<T>::Insert(int Index, T Value)
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
template<typename T>
bool Array<T>::Insert(T Value) // Returns False if the array is not sorted return true if insertion is successful the array is sorted.
{
	if (IsSorted())
	{
		if (length < capacity)
		{
			for (size_t x = length; x >= 0; --x)
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
template<typename T>
void Array<T>::Delete(size_t Index)
{
	if (Index >= 0 && Index < length)
	{
		for (size_t CurrentIndex{ Index }; CurrentIndex < length; ++CurrentIndex)
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
template<typename T>
My_Iterator<T> Array<T>::LinearSearch(T Key)
{
	if (length <= 0)
	{
		return end();
	}
	else
	{
		for (size_t x{ 0 }; x < length; ++x)
		{
			if (Key == MemoryLocation[x])
			{
				Swap((MemoryLocation + x), MemoryLocation);
				return begin();
			}
		}
		return end();
	}
}
template<typename T>
My_Iterator<T> Array<T>::BinarySearch(T Key)
{
	if (IsSorted())
	{
		if (length <= 0)
		{
			end();
		}
		int low = 0, high = length - 1, middle;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (MemoryLocation[middle] == Key)
			{
				return (MemoryLocation + middle);
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
	return end();
}

template<typename T>
T Array<T>::Max() const
{
	T Max = MemoryLocation[0];
	for (int x{ 0 }; x < length; ++x)
	{
		if (MemoryLocation[x] > Max)
		{
			Max = MemoryLocation[x];
		}
	}
	return Max;
}
template<typename T>
T Array<T>::Min() const
{
	T = MemoryLocation[0];
	for (int x{ 0 }; x < length; ++x)
	{
		if (MemoryLocation[x] < Min)
		{
			Min = MemoryLocation[x];
		}
	}
	return Min;
}
template<typename T>
T* Array<T>::GetArray() const
{
	return MemoryLocation;
}
template<typename T>
int Array<T>::Capacity() const
{
	return capacity;
}
template<typename T>
void Array<T>::Reverse()
{
	T* TempArray = new T[capacity];
	for (size_t x{ 0 }, y{ length - 1 }; x < length; ++x, --y)
	{
		TempArray[x] = MemoryLocation[y];
	}
	delete[]MemoryLocation;
	MemoryLocation = TempArray;
	TempArray = nullptr;
}
template<typename T>
void Array<T>::LeftShift()
{
	for (int x{ 0 }; x < length; ++x)
	{
		MemoryLocation[x] = MemoryLocation[x + 1];
	}
	MemoryLocation[length - 1] = 0;
}
template<typename T>
void Array<T>::RightShift()
{
	for (int x = length - 1; x >= 0; --x)
	{
		MemoryLocation[x] = MemoryLocation[x - 1];
	}
	MemoryLocation[0] = 0;
}
template<typename T>
void Array<T>::RightRotate()
{
	T temp = MemoryLocation[length - 1];
	for (int x = length - 1; x >= 0; --x)
	{
		MemoryLocation[x] = MemoryLocation[x - 1];
	}
	MemoryLocation[0] = temp;
}
template<typename T>
void Array<T>::LeftRotate()
{
	T temp = MemoryLocation[0];
	for (int x{ 0 }; x < length; ++x)
	{
		MemoryLocation[x] = MemoryLocation[x + 1];
	}
	MemoryLocation[length - 1] = temp;
}
template<typename T>
bool Array<T>::IsSorted()
{
	for (int x{ 0 }; x < length - 1; ++x)
	{
		if (MemoryLocation[x] > MemoryLocation[x + 1])
		{
			return false;
		}
	}
	return true;
}

template<typename T>
My_Iterator<T> Array<T>::begin()const
{
	return MemoryLocation;
}

template<typename T>
My_Iterator<T> Array<T>::end()const
{
	return(MemoryLocation + length);
}
template<typename T>
void Array<T>::NegativeRotate()
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
template<typename T>
void Array<T>::Merge(const Array<T>& OtherArray)
{
}
template<typename T>
bool Array<T>::MergeAndSort(Array<T>& OtherArray)
{
	if (this->IsSorted() && OtherArray.IsSorted())
	{
		int arr1 = 0, arr2 = 0, arr3 = 0;
		int TempArrayCap = length + OtherArray.length;
		T* TempArray = new T[TempArrayCap];
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
		capacity = TempArrayCap;
		length = TempArrayCap;
		return true;
	}
	else
	{
		return false;
	}
}
template<typename T>
Array<T> Array<T>::Union(Array<T>& Array1, Array<T>& Array2)
{
	int arr1 = 0, arr2 = 0;
	Array<T> TempArray;
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
	for (; arr2 < Array2.length; ++arr2)
	{
		TempArray.push_back(Array2.at(arr2));
	}
	return TempArray;
}
template<typename T>
Array<T> Array<T>::Intersection(Array<T>& Array1, Array<T>& Array2)
{
	int arr1 = 0, arr2 = 0;
	Array<T> TempArray;
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
	if (arr1 > Array1.length)
	{
		while (Array1.MemoryLocation[arr1 - 1] < Array2.MemoryLocation[arr2])
		{
			if (Array1.MemoryLocation[arr1 - 1] == Array2.MemoryLocation[arr2])
			{
				TempArray.push_back(Array1.MemoryLocation[arr1 - 1]);
				break;
			}
			++arr2;
		}
	}
	else
	{
		while (Array1.MemoryLocation[arr1] < Array2.MemoryLocation[arr2 - 1])
		{
			if (Array1.MemoryLocation[arr1] == Array2.MemoryLocation[arr2 - 1])
			{
				TempArray.push_back(Array1.MemoryLocation[arr1 - 1]);
				break;
			}
			++arr1;
		}
	}
	return TempArray;
}
template<typename T>
Array<T> Array<T>::Difference(Array<T>& Array1, Array<T>& Array2)
{
	Array<T> Temp;
	Temp.Merge(Array1);
	return Temp;
}