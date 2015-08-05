#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestConsecutive(const vector<int> &nums)
{
	if (nums.size() <= 1)
		return nums.size();
	unordered_map<int, bool> record;
	for (int i = 0; i < nums.size(); i++)
	{
		record[nums[i]] = 0;
	}

	int max_len = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (record[nums[i]])
			continue;
		int former = nums[i];
		int backer = former;
		while (record.find(++former) != record.end())
			record[former] = 1;

		while (record.find(--backer) != record.end())
			record[backer] = 1;
		
		max_len = max(max_len, (former - backer - 1));
	}
	return max_len;
}

int main()
{
	vector<int> data;
	for (int i = 0; i < 10; i++)
		data.push_back(i);

	for (int i = 8; i < 20; i++)
		data.push_back(i);

	for (int i = 30; i < 35; i++)
		data.push_back(i);

	int result = longestConsecutive(data);
	return 0;
}
