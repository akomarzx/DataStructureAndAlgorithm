#include <iostream>
#include<cstdio>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n > 0)
	{
		towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
		printf("Move Disk from %c to %c\n", from_rod, to_rod);
		towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
	}
}

// Driver code
int main()
{
	int n = 5; // Number of disks
	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
	return 0;
}