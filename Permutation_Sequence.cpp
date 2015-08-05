#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getPermutation(int n, int k)
{
	int factorial = 1;
	vector<int> nums;
	for (int i = 1; i <= n - 1; i++)
	{
		factorial *= i;
		nums.push_back(i);
	}
	nums.push_back(n);

	string result = "";
	k--;
	for (int i = 1; i <= n; i++)
	{
		int i_pos = k / factorial;
		result += to_string(nums[i_pos]);
		k %= factorial;
		if (n != i)
			factorial /= (n - i);
		else
			factorial = 1;
		nums.erase(nums.begin() + i_pos);
	}
	return result;
}

int main()
{
	int n = 4;
	int k = 1;
	for (int i = 1; i <= n; i++)
	{
		k *= i;
	}
	for (int i = 1; i <= k; i++)
	{
		string result = getPermutation(n, i);
		cout << i << " " << result << endl;
	}
	return 0;
}
