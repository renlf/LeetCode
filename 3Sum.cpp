#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& nums, const int begin, const int end)
{
	int povit = nums[begin];
	int i = begin;
	int j = end;
	while (j > i)
	{
		while (nums[j] >= povit && j > i)
			j--;
		nums[i] = nums[j];
		while (nums[i] <= povit && j > i)
			i++;
		nums[j] = nums[i];
	}
	nums[i] = povit;
	return i;
}

void QuickSort(vector<int>& nums, const int begin, const int end)
{
	if (begin < end)
	{
		int pos = Partition(nums, begin, end);
		QuickSort(nums, begin, pos - 1);
		QuickSort(nums, pos + 1, end);
	}
}

vector< vector<int> > threeSum(vector<int>& nums) {
	vector< vector<int> > result;
    if (nums.size() < 3)
        return result;
	QuickSort(nums, 0, nums.size() - 1);
    int l_index = 0;
    int r_index = 0;
	vector<int> sub_array;
    for (int i = 0; i < nums.size(); i++)
    {
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
        
        int remain = 0 - nums[i];
        l_index = i + 1;
        r_index = nums.size() - 1;
        while(l_index < r_index)
        {
            int tmp_2sum = nums[l_index] + nums[r_index];
            if(tmp_2sum == remain)
            {
				sub_array.push_back(nums[i]);
				sub_array.push_back(nums[l_index]);
				sub_array.push_back(nums[r_index]);
				result.push_back(sub_array);
				while (l_index < r_index && nums[l_index] == nums[l_index + 1])
					l_index++;
				while (l_index < r_index && nums[r_index] == nums[r_index - 1])
					r_index--;
				l_index++;
				r_index--;
				sub_array.resize(0, 0);
            }
            else if(tmp_2sum < remain)
            {
                l_index++;
            }
            else
            {
                r_index--;
            }
        }
    }
	return result;
}

int main()
{
	vector<int> nums = { -2, 0, 1, 1, 2};
	/*for (int i = 10; i > 0; i--)
	{
		nums.push_back(i - 5);
		nums.push_back(i - 4);
	}
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	//QuickSort(nums, 0, 9);*/
	vector<vector<int>> result = threeSum(nums);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
