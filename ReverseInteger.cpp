#include <iostream>
#include <limits>
using namespace std;
int reverse(int x)
{
	int op = 1;
	if (x < 0)
		op = -1;
	int result = 0;
	int value = abs(x);
	value = abs(x);
	while (value)
	{
		result = (10 * result);
		result += (value % 10);
		if (result < 0 || (value >= 10 && result > numeric_limits<int>::max() / 10) )
			return 0;
		value = value / 10;
	}
	return op * result;
}

int main()
{
	cout << std::numeric_limits<int>::min() << endl;
	int x = std::numeric_limits<int>::min();
	x = reverse(1534236469);
	return 0;
}
