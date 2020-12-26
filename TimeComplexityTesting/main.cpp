#include<chrono>
#include<iostream>
#include<thread>
#include<vector>
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n > 0)
	{
		towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
		//printf("Move Disk from %c to %c\n" , from_rod , to_rod );
		towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
	}
}

class Timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> StartPoint;
	std::chrono::time_point<std::chrono::steady_clock> TimerEnd;
	std::chrono::duration <float, std::milli> TestDuration;
public:

	Timer()
		:StartPoint{ std::chrono::steady_clock::now() } {}
	~Timer()
	{
		TimerEnd = std::chrono::steady_clock::now();
		TestDuration = std::chrono::duration_cast<std::chrono::milliseconds>(TimerEnd - StartPoint);
		std::cout << TestDuration.count() / 1000 << '\n';
	}
};

void TestingFunction(int Disk)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Number of disk: " << Disk << '\n';
	Timer t1;
	towerOfHanoi(Disk, 'A', 'C', 'B');
}

int main()
{
	std::cout << "Test Starting\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	int TestCount = 10;
	int NumberOfDisk = 10;

	for (int x{ 1 }; x <= TestCount; ++x)
	{
		++NumberOfDisk;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		TestingFunction(NumberOfDisk);
	}

	return 0;
}