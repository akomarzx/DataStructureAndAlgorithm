#include <iostream>

void foo(int x[], int size)
{
	for (int y{ 0 }; y < size; ++y)
	{
		x[y] = y;
	}
	size = 20;
}
int main()
{
	constexpr int size = 5;
	int x[size]{ 2,3,54,6,3 };
	std::cout << *(x + 1) << std::endl;

	return 0;
}