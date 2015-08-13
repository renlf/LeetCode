#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
	if (height.size() < 3)
		return 0;
	int pos = 0;
	int vol = 0;
	while(pos < height.size() - 2)
	{
		int former = pos + 1;
		int min_height = height[pos];
		int sub_pos = 0;
		int sub_max = 0;
		int sub_min = 0;
		while (former < height.size())
		{
			if (height[former] < min_height)
				min_height = height[former];
			if (former > pos + 1 && height[former - 1] < height[former] && sub_max < height[former])
			{
				sub_pos = former;
				sub_max = height[former];
				sub_min = min_height;
			}
			if (height[former] >= height[pos])
				break;
			former++;
		}
		if (sub_pos != 0)
		{		
			int min_h = min(height[pos], height[sub_pos]);
			for (int i = pos + 1; i < sub_pos; i++)
			{
				if (min_h <= height[i])
					continue;
				vol = vol + (min_h - height[i]);
			}
			pos = sub_pos;
		}
		else
		{
			pos++;
		}		
	}
	return vol;
}

int trap2(vector<int>& height) {
	if (height.size() < 2)
		return 0;
	vector<int> lmh;
	int l_max = height[0];
	lmh.resize(height.size());
	for (int i = 1; i < height.size() - 1; i++)
	{
		lmh[i] = l_max;
		if (height[i] > l_max)
			l_max = height[i];
	}
	int r_max = height[height.size() - 1];
	int vol = 0;
	for (int j = height.size() - 2; j > 0; j--)
	{
		int min_h = min(r_max, lmh[j]);
		if (min_h > height[j])
			vol = vol + (min_h - height[j]);
		if (height[j] > r_max)
			r_max = height[j];
	}

	return vol;
}

int main()
{
	vector<int> data = {9, 6, 8, 8, 5, 6, 3};
	int result = trap(data);
	return 0;
}
