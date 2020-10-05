#include <iostream>

float e(float x, float n)
{
	static float power = 1.0f, factorial = 1.0f;
	float result;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		result = e(x, n - 1); 
		power *= x;
		factorial *= n;
		return result + power / factorial;
	}
}

int main()
{
 	std::cout << e(2.0f, 1.0f) << '\n';
 	return 0;
}