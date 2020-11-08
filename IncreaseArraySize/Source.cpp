#include<iostream>
#include<cstdio>

int main()
{
	
	int size = 10;
	int* array1 = nullptr;
	int* array2 = nullptr;

	array1 = new int[size]{ 1,2,3,4,5,6,7,8,9,10 };
	
	for (int x{ 0 }; x < size; ++x)
	{
		printf("%d \n", array1[x]);
	}

	array2 = new int[size + static_cast<long long>(20)];

	for (int x{ 0 }; x < size; ++x)
	{
		array2[x] = array1[x]; // copy all the contents of array to the new resized array
	}

	delete[] array1; // free up the memory
	array1 = array2; // move ownership of the new pointer to the original pointer
	array2 = nullptr; //set the temp pointer to null to avoid dangling pointers 



	delete[] array1;
	delete[] array2;
	return 0;
	std::cout << "Hello World\n";
}
