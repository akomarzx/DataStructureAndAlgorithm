#include<iostream>
#include"IntArray.h"
#include<vector>

#include<set>
int main()
{
	IntArray myarray1{ 1,3,5,7,9,11};
	IntArray myarray2{ 2,4,6,8};

	myarray1.MergeAndSort(myarray2);

	myarray1.Print();
	return 0;
}