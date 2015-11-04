#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++)
        	q.push(nums[i]);
        for (int i = 1; i < k; i++)
        	q.pop();
        return q.top();
	}

	int findKthLargest2(vector<int>& nums, int k) {
		int l = 0, r = nums.size() - 1;
		k = nums.size() - k;
		while (l < r)
		{
			int povit = nums[l];
			int p = l;
			int q = r;
			while (p < q)
			{
				while (p < q && nums[q] >= povit) q--;
				nums[p] = nums[q];
				while (p < q && nums[p] <= povit) p++;
				nums[q] = nums[p];
			}
			nums[p] = povit;
			if (p == k)
				return povit;
			else if (p > k)
				r = p - 1;
			else
				l = p + 1;
		}
		return nums[k];
    }
};
