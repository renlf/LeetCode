#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea2(vector<int>& height) {
	int max_area = 0;
	int min_height = 0;
	
	for (int i = 0; i < height.size(); i++)
	{
		min_height = height[i];
		int tmp_area = 0;

		for (int j = i + 1; j < height.size(); j++)
		{
			if (height[j] < min_height)
			{
				min_height = height[j];
			}
			tmp_area = min_height * (j - i);
			if (tmp_area > max_area)
			{
				max_area = tmp_area;
			}
		}
	}
	return max_area;
}

int sub_area(int * height, int begin, int end)
{
	if (begin > end)
	{
		return 0;
	}
	if (begin == end)
	{
		return *height;
	}
	int min_height = height[begin];
	int min_index = begin;
	
	for (int i = begin + 1; i <= end; i++)
	{
		if (height[i] < min_height)
		{
			min_height = height[i];
			min_index = i;
		}
	}
	int max_value = min_height * (end - begin + 1);
	
	int left_area = sub_area(height, begin, min_index - 1);
	int right_area = sub_area(height, min_index + 1, end);
	if (max_value < left_area)
	{
		max_value = left_area;
	}
	if (max_value < right_area)
	{
		max_value = right_area;
	}
	return max_value;
}

int maxArea(int * height, int heightsize)
{
	return sub_area(height, 0, heightsize - 1);
}

int maxArea3(vector<int> &height)
{
	int l_index = 0;
	int r_index = height.size() - 1;
	int max_value = 0;
	while (l_index < r_index)
	{
		int tmp_value = 0;
		tmp_value = (r_index - l_index) * min(height[l_index], height[r_index]);
		if (tmp_value > max_value)
		{
			max_value = tmp_value;
		}
		if (height[l_index] < height[r_index])
		{
			l_index++;
		}
		else
			r_index--;
	}
	return max_value;
}

int main()
{
	int data[] = { 1, 2, 4, 3 };
	int result = maxArea(data, 4);
	cout << result << endl;
	return 0;
}
