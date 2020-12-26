#include<iostream>

namespace Practice
{
	int exp(int base, int power)
	{
		if (power == 0)
		{
			return 1;
		}
		if (power % 2 == 0)
		{
			return exp(base * base, (power / 2));
		}
		else
		{
			return base * exp(base * base, ((power - 1) / 2));
		}
	}
}
int main()
{
	std::cout << Practice::exp(2, 4) << '\n';
	std::cout << '\n' << '/n';
	return 0;
}