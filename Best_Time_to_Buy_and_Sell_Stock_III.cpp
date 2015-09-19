#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;
	int ret = 0;
	vector<int> dp(prices.size(), 0);
	int minp = prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < minp)
		{
			minp = prices[i];
			dp[i] = ret;
		}
		else
		{
			dp[i] = max(ret, prices[i] - minp);
			ret = dp[i];
		}
	}
	int maxp = prices[prices.size() - 1];
	int sub_ret = 0;
	for (int i = prices.size() - 2; i >= 1; i--)
	{
		if (maxp < prices[i])
			maxp = prices[i];
		else
		{
			sub_ret = max(maxp - prices[i], sub_ret);
			ret = max(ret, dp[i - 1] + sub_ret);
		}
	}
	return ret;
}

int main()
{
	vector<int> data = { 7, 11, 4, 1, 2 };
	int ret = maxProfit(data);
	return 0;
}
