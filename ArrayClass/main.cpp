#include<iostream>
#include"Array.h"
#include<vector>
#include<string>
#include<iomanip>
int main()
{
	Array<int> array1{ 1,3,5,7,9 };
	Array<int> array2{ 2,4,6,8,10 };
	array1.MergeAndSort(array2);
	array1.Reverse();
	array1.Print();
	array1.RightRotate();
	array1.Print();
	return 0;
}