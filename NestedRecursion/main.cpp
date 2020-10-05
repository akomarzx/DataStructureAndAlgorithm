#include<iostream>

int foo(int n)
{
	if (n > 100)
	{
		return n - 10;
	}
	else
	{
		return foo(foo(n + 11));
	}
}

int main()
{

	foo(95);
	return 0;
}  