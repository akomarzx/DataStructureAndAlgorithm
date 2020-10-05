#include<iostream>

void foo(int n)
{
	if (n > 0)
	{
		printf("%d\n", n);
		foo(n - 1);
		foo(n - 1);
	 }
}

int main()
{
	foo(3);

	return 0;
}