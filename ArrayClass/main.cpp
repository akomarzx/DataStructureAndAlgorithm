#include<iostream>
#include"IntArray.h"
#include<vector>


int main()
{
	IntArray myArray{ 3,6,10,22,30, 43 };
	myArray.Print();
	myArray.RightShift();
	myArray.Print();

	return 0;
}