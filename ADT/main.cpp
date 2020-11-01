#include<iostream>
#include<cstdlib>
#include<vector>
struct Array
{
	int* A;
	int size;
	int length;
};
void foo()
{	
	std::cout << "Hello world\n";
}


int main()
{
	/*
	Array arr;
	std::cout << "Enter the size of array: ";
	std::cin >> arr.size;
	arr.A = new int[arr.size];
	arr.length = 0;
	
	std::cout << "Enter the number of Elements: ";
	int num_of_elements{ 0 };
	std::cin >> num_of_elements;

	for (unsigned int x{ 0 }; x < num_of_elements; ++x)
	{
		std::cin >> arr.A[x];
	}
	arr.length = num_of_elements;

	for (unsigned int y{ 0 }; y < arr.length; ++y)
	{
		std::cout << arr.A[y] << '\n';
	}
	*/

	std::vector<int> myvec;
	std::cout << myvec.capacity()<< '\n';
	myvec.reserve(2000);
	std::cout << myvec.capacity() << '\n';



	return 0;
}