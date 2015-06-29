#include <iostream>
#include <limits>

using namespace std;

bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	int digit = 1;
	int max_devide = 1;
	int value = x;
	while ((value / 10) != 0)
	{
		value = value / 10;
		digit++;
		max_devide *= 10;
	}
	int mid = digit / 2;
	value = x;
	while (digit > mid)
	{
		int l_part = (value / max_devide) % 10;
		int r_part = x % 10;
		if (l_part == r_part)
		{
			max_devide = max_devide / 10;
			x = x / 10;
			digit--;
			continue;
		}
		else
			return false;
	}

	return true;
}

bool isPalindrome2(int x)
{
	if (x < 0)
		return false;

	int max_devide = 1;
	int value = x;
	while ((x / max_devide) >= 10)
	{
		max_devide *= 10;
	}
	while (x > 0)
	{
		int l_part = x / max_devide;
		int r_part = x % 10;
		if (l_part != r_part)
		{
			return false;
		}
		x = (x % max_devide) / 10;
		max_devide = max_devide / 100;
	}
	return true;
}

int main()
{
	int num = 1001;
	bool result = isPalindrome2(num);
	cout << result << endl;
	return 0;
}
