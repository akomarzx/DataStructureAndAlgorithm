#include <iostream>

long long fib(int n)
{
	if (n == 1 || n == 0)
	{
		return n;
	}
	else
	{
		return (fib(n - 1) + fib(n - 2));
	}
}

int main()
{
	std::cout << fib(20) << '\n';
	return 0;
}