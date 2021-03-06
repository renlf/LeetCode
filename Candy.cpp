#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
	if (ratings.size() == 0)
		return 0;

	int ret = 0;
	vector<int> dp(ratings.size(), 1);
	for (int i = 1; i < ratings.size(); i++)
	{
		if (ratings[i] > ratings[i - 1])
			dp[i] = dp[i - 1] + 1;
	}
	ret = dp[dp.size() - 1];
	for (int i = ratings.size() - 2; i >= 0; i--)
	{
		if (ratings[i] > ratings[i + 1])
			dp[i] = max(dp[i], dp[i + 1] + 1);
		ret += dp[i];
	}
	return ret;
}
