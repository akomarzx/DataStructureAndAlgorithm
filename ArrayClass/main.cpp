#include<iostream>
#include<vector>
#include<thread>
void Swap(int* Value_A, int* Value_B)
{
	int Temp = *Value_A;
	*Value_A = *Value_B;
	*Value_B = Temp;
}
class IntArray
{
private:
	int* MemoryLocation;
	size_t Capacity;
	size_t Length;
public:
	IntArray(const IntArray&) = delete;
	~IntArray()
	{
		delete[] MemoryLocation;
	}
	IntArray()
	:Capacity{10},Length{0}
	{
		MemoryLocation = new int[Capacity];
	}
	IntArray(size_t Count)//Allocates n Memory for the array  
		:Capacity{ Count }, Length{ 0 }
	{
		MemoryLocation = new int[Capacity];
	}
	IntArray(std::initializer_list<int>Initial_Elements)
		:Capacity{Initial_Elements.size()}, Length{Initial_Elements.size()}
	{
		MemoryLocation = new int[Initial_Elements.size()];
		int CurrentIndex = 0;
		for (auto Element : Initial_Elements)
		{
			MemoryLocation[CurrentIndex] = Element;
			++CurrentIndex;
		}
	}
	void Print()const
	{
		std::cout << '{';
		for (size_t Index{ 0 }; Index < Length; ++Index)
		{
			std::cout << MemoryLocation[Index]<< ' ';
		}
		std::cout << '}' << '\n';
	}
	void Add(int New_Element)
	{
		if (Length < Capacity)
		{
			MemoryLocation[Length] = New_Element;
			++Length;
		}
	}
	int& at(size_t index)
	{	
			if (index < Length)
			{
				return (MemoryLocation[index]);
			}
			else
			{
				throw "Testing";
			}	
	}
	size_t Size()const
	{
		return Length;
	}
	void Insert(int Index, int Value)
	{
		if (Index >= 0 && Index <= Length)
		{
			for (int x = Length; x > Index; --x)
			{
				MemoryLocation[x] = MemoryLocation[x - 1];
			}
			MemoryLocation[Index] = Value;
			++Length;
		}
	}
	void Delete(int Index)
	{
		if (Index >= 0 && Index < Length)
		{
			for (int CurrentIndex{ Index }; CurrentIndex < Length; ++CurrentIndex)
			{
				MemoryLocation[CurrentIndex] = MemoryLocation[CurrentIndex + 1];
			}
			MemoryLocation[Length - 1] = 0;
			--Length;
		}
		else
		{
			throw 1;
		}
	}
	int LinearSearch(int Key)//Linear Search Version returns the index if search is successful -1 if search is unsuccessful
	{
		if (Length <= 0)
		{
			return -1;
		}
		else
		{
			for (int x{ 0 }; x < Length; ++x)
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
	int BinarySearch(int Key)//Binary Search Version returns the index if search is successful -1 if search is unsuccessful
	{
		if (Length <= 0)
		{
			return -1;
		}
		int low = 0, high = Length - 1, middle;
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
	int* GetArray()
	{
		return MemoryLocation;
	}
};

int BinarySearch(int* MyArray, int low, int high, int key)
{
	if (low <= high)
	{
		int middle = (low + high) / 2;
		if (MyArray[middle] == key)
		{
			return middle;
		}
		else if (MyArray[middle] > key)
		{
			return BinarySearch(MyArray, low, middle - 1, key);
		}
		else
		{
			return BinarySearch(MyArray, middle + 1, high, key);
		}
	}
	return -1;
}

int main()
{
	IntArray MyArray{ 10,20,30,40,50,60,70,80,90,100,110,120 };
	std::cout << BinarySearch(MyArray.GetArray(), 0, MyArray.Size() - 1, 110);
	return 0;
}