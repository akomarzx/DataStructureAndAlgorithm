#include<iostream>
#include<vector>

int main()
{
	int* Array1 = new int[20];

	Array1[0] = 21;
	Array1[1] = 200;
	std::cout << Array1[1] << '\n';
	std::vector<int> MyVector{ 1,2,3,4,5,6,7 };

	

	return 0;
}