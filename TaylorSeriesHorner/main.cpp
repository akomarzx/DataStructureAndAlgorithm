#include<iostream>

double taylor_iterative(int x, int n)
{
	double s = 1;
	int i;
	double num = 1;
	double den = 1.0f;
	for (i = 1; i <= n; i++)
	{
		num *= x;
		den *= i;
		s += num / den;
	}
	return s;
}
float taylor_recursive(int base, int exponent)
{
	static float s;
	if (exponent == 0)
	{
		return s;
	}
	s = 1 + base * s / exponent;
	return taylor_recursive(base, exponent - 1);
}

int main()
{
	std::cout << taylor_recursive(1, 10) << std::endl;
	return 0;
}