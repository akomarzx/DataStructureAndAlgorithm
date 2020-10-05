#include<iostream>

int Sum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return (Sum(n - 1) + n);
	}
}

int main()
{
	int n = 20;
	printf("%d\n", Sum(n));
}