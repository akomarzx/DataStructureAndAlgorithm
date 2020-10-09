#include <iostream>

int foo(int n)
{
	int x = 1, k;
	if (n == 1)
	{
		return x;
	}
	for (k = 1; k < n; ++k)
	{
		x = x + foo(k) * foo(n - k);
	}
	return x;
}

int main()
{
	std::cout << foo(5);
x`}