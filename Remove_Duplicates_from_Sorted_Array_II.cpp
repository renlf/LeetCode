#include <vector>

using namespace std;

int removeDuplicates(vector<int> nums)
{
	if (nums.size() <= 2)
		return nums.size();
	int former = 1;
	int backer = 0;
	bool flag = false;
	while (former < nums.size())
	{
		if (nums[backer] != nums[former])
		{
			nums[++backer] = nums[former];
			flag = false;
		}
		else
		{
			if (flag == false)
			{
				nums[++backer] = nums[former];
				flag = true;
			}
		}
		former++;
	}
	return backer + 1;
}

int removeDuplicates2(vector<int> nums)
{
    if (nums.size()  <= 2)
        return nums.size();

    int former = 2;
    int backer = 2;
    while (former < nums.size())
    {
        if (nums[backer - 2] !=  nums[former])
        {
            nums[backer++] = nums[former];
        }
        former++;
    }
    return backer;
}

int main()
{
	vector<int> data;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			data.push_back(i);
		}
	}
	int result = removeDuplicates2(data);
	return 0;
}
