#include<iostream>
#include"IntArray.h"
#include<vector>

int main()
{
	IntArray myArray{3,6,10};
	
	std::cout <<"Current Capacity: " << myArray.Capacity() << '\n';
	std::cout << "Current Length: " << myArray.Size() << '\n';

	myArray.Add(20);

	std::cout << "Current Capacity: " << myArray.Capacity() << '\n';
	std::cout << "Current Length: " << myArray.Size() << '\n';
	myArray.Print();
	std::cout << "Current Length: " << myArray.Size() << '\n';

	myArray.Delete(0);
	
	myArray.Print();
	std::cout << "Current Length: " << myArray.Size() << '\n';


	return 0;
}