#include<iostream>

void fooB(int n);

void fooA(int n)
{
	if (n > 0)
	{
		printf("%d\n", n);
		fooB(n - 1);
	}
}

void fooB(int n)
{
	if (n > 0)
	{
		printf("%d\n", n);
		fooA(n - 3);
	}
}

int main()
{
	
	fooA(20);
	return 0;
}