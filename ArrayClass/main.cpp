#include<iostream>
#include"IntArray.h"
#include<vector>


int main()
{
	IntArray myArray{ 3,6,10,22,30, 43 };
	if (myArray.IsSorted())
	{
		std::cout << "Sorted\n";
	}
	else
	{
		std::cout << "Not Sorted\n";
	}
	myArray.Print();
	myArray.Insert(18);
	myArray.Print();
	if (myArray.IsSorted())
	{
		std::cout << "Sorted\n";
	}
	else
	{
		std::cout << "Not Sorted\n";
	}
	std::cout << myArray.BinarySearch(18);
	return 0;
}