#include<iostream>
#include<string>

int numberoffunctioncalls = 0;
void swap(std::string& input, int from, int to)
{
	char temp = input.at(from);
	input.at(from) = input.at(to);
	input.at(to) = temp;
}
void permute(std::string& input, int low, int high)
{
	++numberoffunctioncalls;
	int i;
	if (low == high)
	{
		std::cout << input <<"=="<< '\n';
	}
	else
	{
		for (i = low; i <= high; ++i)
		{
			swap(input, low, i);
		
			permute(input, low + 1, high);
		
			swap(input, low, i);
		}
	}
}	

int main()
{
	std::string input{ "Rebekah" };
	permute(input, 0, input.size() - 1);
	std::cout << numberoffunctioncalls << '\n';
	return 0;
}