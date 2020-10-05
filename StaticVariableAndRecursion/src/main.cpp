#include<iostream>

int foo(int n)
{
	static int x = 0;// the variable will be initialized once and it will stay in memory for the lifetime of the program
	if (n > 0)		//Each subsequent call to the function the static variable will retain its value after function executes.
	{
		++x;
		return foo(n - 1) + x;
	}
	return 0;
}


int main()
{
	int y = 5;
	printf("\n%d\n", foo(y));
}