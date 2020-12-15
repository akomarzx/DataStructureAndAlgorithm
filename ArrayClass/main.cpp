#include<iostream>
#include"IntArray.h"
#include<vector>


int main()
{
	IntArray array1{2,5,9,12,16,18 };
	IntArray array2{5,10,16,17,18};
	IntArray array3 = SetOperation::Difference(array1, array2);
	
	array3.Print();

	return 0;
}