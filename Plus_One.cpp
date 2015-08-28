#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	bool flag = false;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		int new_val;
		if (flag || i == digits.size() - 1)
		{
			new_val = digits[i] + 1;
			digits[i] = new_val % 10;
			if (new_val >= 10)
			{
				flag = true;				
			}
			else
			{
				return digits;
			}
		}
	}
	if (flag)
		digits.insert(digits.begin(), 1);
	return digits;
}
