#include <vector>
#include <string>

using namespace std;

int nums_bit(int a)
{
	int ret = 1;
	while (a)
	{
		ret *= 10;
		a /= 10;
	}
	return ret;
}

bool judge(long long a, long long b)
{
	long long a_bit = nums_bit(a);
	long long b_bit = nums_bit(b);

	if ((a * b_bit + b) >= (b * a_bit + a))
		return true;
	else
		return false;
}

int partition(vector<int> &nums, int s, int e)
{
	int tmp = nums[s];
	int i = s;
	int j = e;
	while (i < j)
	{
		while (i < j && judge(nums[j], tmp))
			j--;
		nums[i] = nums[j];
		while (i < j && judge(tmp, nums[i]))
			i++;
		nums[j] = nums[i];
	}
	nums[i] = tmp;
	return i;
}

void QSort(vector<int> &nums, int s, int e)
{
	if (s < e)
	{
		int pos = partition(nums, s, e);
		QSort(nums, s, pos - 1);
		QSort(nums, pos + 1, e);
	}
}

string largestNumber(vector<int>& nums) {
	int s = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			swap(nums[s], nums[i]);
			s++;
		}
	}

	if (s == nums.size())
	{
		return "0";
	}

	QSort(nums, s, nums.size() - 1);
	string ret = "";
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		ret += to_string(nums[i]);
	}
	return ret;
}
