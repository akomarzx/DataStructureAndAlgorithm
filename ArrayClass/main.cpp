#include<iostream>
#include<vector>
#include<thread>
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
};


int main()
{
	IntArray myArray{ 10,20,30,40,50,60,70,80,90,100 };
	std::cout << myArray.Size() << '\n';
	myArray.Print();
	myArray.Delete(0);
	std::cout << myArray.Size() << '\n';
	myArray.Print();
	return 0;
}