#include<iostream>

constexpr float PassingAverage = 60.0f;

void ScorePercentage(int Items)
{
	static const int NumberOfItems = Items;
	float Percentage = (static_cast<float>(Items) / NumberOfItems) * 100;
	if (Percentage < PassingAverage)
	{
		return;
	}
	else
	{
		int TempItem = Items - 5;
		ScorePercentage(TempItem);
		std::cout << Percentage << " % :" << Items << '\n';
	}
}

int main()
{
	ScorePercentage(30);
	return 0;
}