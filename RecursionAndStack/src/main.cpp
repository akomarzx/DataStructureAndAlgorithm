#include<iostream>
#include<vector>

void foo(int n)
{
	if (n > 0)
	{
		printf("%d\n", n);	
		foo(n - 1);
	}
}

int main(int argc , char** argv)
{
	foo(5);
}
