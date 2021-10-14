#include<iostream>

class Diagonal
{
private:
	int size;
	int* Array;
public:
	Diagonal(int size)
		:size{size} , Array{new int[size]}
	{

	}
	~Diagonal() { delete[] Array; }
	void Set(int row, int column, int element)
	{
		if (row == column)
		{
			Array[row - 1] = element;
		}
	}
	int Get(int row, int column)const
	{
		if (row == column)
		{
			return Array[row - 1];
		}
		return 0;
	}
	void Display()const
	{
		for (int x{ 0 }; x < size; ++x)
		{
			for (int y{ 0 }; y < size; ++y)
			{
				if (x == y)
				{
					std::cout << Array[x] << ",";
				}
				else
				{
					std::cout << "0,";
				}
			}
			std::cout << '\n';
		}
	}
};

int main()
{
	Diagonal matrix(5);

	matrix.Set(1, 1, 5);
	matrix.Set(2, 2, 4);
	matrix.Set(3, 3, 5);
	matrix.Set(4, 4, 6);
	matrix.Set(5, 5, 7);

	matrix.Display();

	return 0;
}