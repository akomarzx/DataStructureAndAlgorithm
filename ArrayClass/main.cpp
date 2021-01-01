#include"Array.h"
int main()
{
	Array<int> array1 {1,2,3,4,5,6,7,8};
	array1.emplace_back(20);
	array1.GetArray();
	return 0;
}