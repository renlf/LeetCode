#include <climits>
#include <algorithm>

int divide(int dividend, int divisor) {
	if (dividend == 0) return 0;
	if (dividend == divisor) return 1;

	int sign = 1;
	if (dividend < 0) sign *= -1;
	if (divisor < 0)  sign *= -1;
 
	unsigned int new_dividend = abs(dividend < 0 ? -dividend : dividend);
	unsigned int new_divisor = abs(divisor < 0 ? -divisor : divisor);

	if (new_dividend < new_divisor)
		return 0;

	unsigned int count = 1;  
	while (new_divisor < new_dividend)
	{
		new_divisor = new_divisor << 1;
		count = count << 1;
	}
	
	unsigned int result = 0;

	while (new_dividend >= abs(divisor < 0 ? -divisor : divisor))
	{
		while (new_dividend >= new_divisor)
		{
			new_dividend -= new_divisor;
			result += count;
		}
		new_divisor = new_divisor >> 1;
		count = count >> 1;
	}
	if (sign > 0)
	{
		result = result >= INT_MAX ? INT_MAX : result;
	}
	return result * sign;
}

int main()
{
	int a = INT_MIN;
	int b = -1;
	int result = divide(a, -1);
	return 0;
}
