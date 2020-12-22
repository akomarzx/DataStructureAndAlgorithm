#include<iostream>
#include"Array.h"
#include<vector>


int main()
{
	Array array1{2,5,9,12,16,18 };
	Array array2{5,10,16,17,18};
	Array array3 = SetOperation::Union(array1, array2);
	
	array3.Print();

	return 0;
}