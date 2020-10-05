#include<iostream>
#include<vector>
unsigned long long fib(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		std::vector<int> vec{ 0,1 };
		for (int i{ 1 }; i <= n - 1; ++i)
		{
			vec.push_back(vec.back() + vec.at(i - 1));
		}
		return (vec.back());
	}
}


int main()
{
	int input{ 0 };
	
	for (int x{ 0 }; x <= 20; ++x)
	{
		std::cout << "Fibonacci of " << x << " is = " << fib(x) << '\n';
	}
	return 0;
}