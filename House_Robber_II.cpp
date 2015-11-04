#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int N = nums.size();
		if (N == 0)
			return 0;
		if (N == 1)
			return nums[0];
		if (N == 2)
			return max(nums[0], nums[1]);
		vector<int> dp(N);

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for (int i = 2; i < N - 1; i++)
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		int val = dp[N - 2];
		dp.resize(N, 0);
		dp[1] = nums[1];
		dp[2] = max(nums[1], nums[2]);
		for (int i = 3; i < N; i++)
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		return max(val, dp[N - 1]);
	}
};
