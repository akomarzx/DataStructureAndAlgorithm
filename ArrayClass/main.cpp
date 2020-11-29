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
	size_t capacity;
	size_t length;
	void ReallocateAndResize()
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
public:
	IntArray(const IntArray&) = delete;
	~IntArray()
	{
		delete[] MemoryLocation;
	}
	IntArray()
	:capacity{10},length{0}
	{
		MemoryLocation = new int[capacity];
	}
	IntArray(size_t Count)//Allocates n Memory for the array  
		:capacity{ Count }, length{ 0 }
	{
		MemoryLocation = new int[capacity];
	}
	IntArray(std::initializer_list<int>Initial_Elements)
		:capacity{Initial_Elements.size()}, length{Initial_Elements.size()}
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
		for (size_t Index{ 0 }; Index < length; ++Index)
		{
			std::cout << MemoryLocation[Index]<< ' ';
		}
		std::cout << '}' << '\n';
	}
	void Add(int New_Element)
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
	int& at(size_t index)//Element Access with bounds Checking
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
	size_t Size()const
	{
		return length;
	}
	void Insert(int Index, int Value)
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
	void Delete(int Index)
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
	int LinearSearch(int Key)//Linear Search Version returns the index if search is successful -1 if search is unsuccessful
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
	int BinarySearch(int Key)//Binary Search Version returns the index if search is successful -1 if search is unsuccessful
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
	int Max()const // Return the Highest Element in the array
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
	int Min()const // Return the Lowest Element in the array
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
	int Sum()const
	{
		int sum = MemoryLocation[0];
		for (int x{ 1 }; x < length; ++x)
		{
			sum += MemoryLocation[x];
		}
		return sum;
	}
	float Average()const
	{
		return Sum() / static_cast<float>(length);
	}
	int* GetArray()
	{
		return MemoryLocation;
	}
	int Capacity()const
	{
		return capacity;
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
	IntArray myArray{3,6,10};
	
	std::cout <<"Current Capacity: " << myArray.Capacity() << '\n';
	std::cout << "Current Length: " << myArray.Size() << '\n';

	myArray.Add(20);

	std::cout << "Current Capacity: " << myArray.Capacity() << '\n';
	std::cout << "Current Length: " << myArray.Size() << '\n';
	return 0;
}