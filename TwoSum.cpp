#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int Sort(vector<int> &nums, int start, int end)
{
	int i = start;
	int j = end;
	int povit = nums[start];
	int array_size = nums.size();
	while (i < j)
	{
		while ((i < j) && (nums[j] >= povit))
			j--;
		nums[i] = nums[j];
		while ((i < j) && (nums[i] <= povit))
			i++;
		nums[j] = nums[i];
	}
	nums[i] = povit;
	return i;
}

void QuickSort(vector<int> &nums, int start, int end)
{
	if (nums.empty())
	{
		return;
	}
	if (start < end-1)
	{
		int array_size = nums.size();
		int position = Sort(nums, start, end);
		QuickSort(nums, start, position - 1);
		QuickSort(nums, position + 1, end);
	}
}




vector<int> twosum(vector<int>& nums, int target)
{
	vector<int> result;
	result.resize(0);
	if (nums.empty())
	{
		return result;
	}
	bool find = false;
	int array_size = nums.size();
	for (int i = 0; (i < array_size) && (!find); i++)
	{
		int remain = target - nums[i];
		int j = i + 1;
		for (; j < array_size; j++)
		{
			if (nums[j] == remain)
			{
				find = true;
				result.push_back(i + 1);
				result.push_back(j + 1);
				break;
			}
		}
		
	}
	return result;
}

vector<int> twosum2(vector<int>& nums, int target)
{
	vector<int> result;
	result.resize(0);
	if (nums.empty())
	{
		return result;
	}
	multimap<int, int> nums_map;
	
	for (int i = 0; i < nums.size(); i++)
	{
		nums_map.insert(pair<int, int> (nums[i],i+1));
	}

	int index1 = 0;
	int index2 = 0;
	//pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ret;
	

	multimap<int, int>::iterator iter;
	multimap<int, int>::iterator find_iter;
	for (iter = nums_map.begin(); iter != nums_map.end(); iter++)
	{
		//ret = nums_map.equal_range(iter->first);
		int tmp = target - iter->first;
		if ((find_iter=nums_map.find(tmp))==nums_map.end())
		{
			continue;
		}
		else
		{
			//result.push_back(iter->second);
			index1 = iter->second;
			if ((iter->first == target) || ((2 * iter->first) == target))
			{
				nums_map.erase(iter);
				if ((find_iter = nums_map.find(tmp)) == nums_map.end())
				{
					continue;
				}
			}

			//result.push_back(find_iter->second);
			index2 = find_iter->second;
			break;
		}
	}

	if (index1 < index2)
	{
		result.push_back(index1);
		result.push_back(index2);
	}
	else
	{
		result.push_back(index2);
		result.push_back(index1);
	}
	return result;
}

vector<int> twosum3(vector<int>& nums, int target)
{
	vector<int> result;
	result.resize(0);
	if (nums.empty())
	{
		return result;
	}

	map<int, int> nums_maps;
	for (int i = 0; i < nums.size(); i++)
	{
		//nums_maps.insert(pair<int,int> (nums[i], i+1));
		nums_maps[nums[i]] = i + 1;
	}
	map<int, int>::iterator iter;
	for (int i = 0; i < nums.size(); i++)
	{
		int remain = target - nums[i];
		iter = nums_maps.find(remain);
		if (iter!=nums_maps.end())
		{
			result.push_back(i+1);
			result.push_back(iter->second);
			//result.push_back(nums_maps[remain]);
			break;
		}
	}
	return result;
}

vector<int> twosum4(vector<int> &nums, int target)
{
	vector<int> result;
	result.resize(0);
	if (nums.empty())
	{
		return result;
	}
	map<int, int> nums_map;
	map<int, int>::iterator iter;
	for (int i = 0; i < nums.size(); i++)
	{
		int remain = target - nums[i];
		iter = nums_map.find(remain);
		if (iter != nums_map.end())
		{
			result.push_back(iter->second + 1);
			result.push_back(i + 1);
		}
		nums_map[nums[i]] = i;
	}
	return result;
}

int main()
{
	vector<int> data_set = { 2, 1, 9, 4, 4, 56, 90, 3 };
	/*data_set.resize(0);
	for (int i = 10; i > 0 ; i--)
	{
		data_set.push_back(i);
	}*/

	//QuickSort(data_set, 0, 9);
	
	vector<int> result = twosum4(data_set, 8);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}