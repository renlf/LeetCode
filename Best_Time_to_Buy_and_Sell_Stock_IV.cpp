#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
	int ret = 0;
	if (k >= prices.size() / 2)
	{
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
				ret += (prices[i] - prices[i - 1]);
		}
		return ret;
	}

	vector<vector<int>> buy(prices.size(), vector<int>(k + 1, INT_MIN));
	vector<vector<int>> sell(prices.size(), vector<int>(k + 1, 0));

	for (int i = 0; i <= k; i++)
	{
		buy[0][i] = -prices[0];
	}

	for (int i = 1; i < prices.size(); i++)
	{
		buy[i][0] = max(buy[i-1][0], -prices[i]);
		for (int j = 1; j <= k; j++)
		{
			buy[i][j] = max(sell[i - 1][j] - prices[i], buy[i - 1][j]);
			sell[i][j] = max(buy[i - 1][j - 1] + prices[i], sell[i - 1][j]);
		}
	}

	return max(buy[prices.size() - 1][k], sell[prices.size() - 1][k]);
}

int maxProfit2(int k, vector<int>& prices) {
	int ret = 0;
	if (k >= prices.size() / 2)
	{
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
				ret += (prices[i] - prices[i - 1]);
		}
		return ret;
	}

	vector<int> buy(k + 1, INT_MIN);
	vector<int> sell(k + 1, 0);

	buy[0] = -prices[0];

	for (int i = 1; i < prices.size(); i++)
	{
		buy[0] = max(buy[0], -prices[i]);
		for (int j = 1; j <= k; j++)
		{
			buy[j] = max(sell[j] - prices[i], buy[j]);
			sell[j] = max(buy[j - 1] + prices[i], sell[j]);
		}
	}

	return max(buy[k], sell[k]);
}

int maxProfit3(int k, vector<int>& prices) {
	int ret = 0;
	if (k >= prices.size() / 2)
	{
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
				ret += (prices[i] - prices[i - 1]);
		}
		return ret;
	}

	vector<int> buy(k + 1, INT_MIN);
	vector<int> sell(k + 1, 0);

	buy[0] = -prices[0];

	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = k; j >=1 ; j--)
		{
		    sell[j] = max(buy[j] + prices[i], sell[j]);
			buy[j] = max(sell[j - 1] - prices[i], buy[j]);
		}
	}

	return max(buy[k], sell[k]);
}
