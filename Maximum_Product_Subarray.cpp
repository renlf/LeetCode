#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
	vector<vector<int>> dp(nums.size(), vector<int>(2));
	dp[0][0] = nums[0];
	dp[0][1] = nums[0];
	int max_val = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		dp[i][0] = max(nums[i], max(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
		dp[i][1] = min(nums[i], min(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
		max_val = max(max_val, dp[i][0]);
	}
	return max_val;
}
