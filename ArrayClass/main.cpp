#include<iostream>
#include"Array.h"
#include<vector>
#include<string>
#include<iomanip>

int main()
{
	Array<int> array1{ 2,3,3,5,7,9,9,10,15,30,3,30,3 };
	
	Array<int> Hashtable(array1.Max() + 1 , 0);
	
	for (int x{ 0 }; x < array1.Size(); ++x)
	{
		++(Hashtable.at(array1.at(x)));
	}
	for (int x{ 0 }; x < Hashtable.Size(); ++x)
	{
		if (Hashtable.at(x) > 1)
		{
			std::cout << "Element : " << x << " appeared " << Hashtable.at(x) <<" times"<< '\n';
		}
	}
	return 0;
}