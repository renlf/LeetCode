#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;
	int ret = 0;
	int minp = prices[0];
	int maxp = prices[0];
	for (int i = 1; i < prices.size() - 1; i++)
	{
		int j = i;
		while (prices[i] == prices[i + 1])
		{
			i++;
		}
		if (prices[i] < prices[j - 1] && prices[i] < prices[i + 1])
		{
			minp = prices[i];
		}
		if (prices[i] > prices[j - 1] && prices[i] > prices[i + 1])
		{
			maxp = prices[i];
			ret += maxp - minp;
		}
	}
	if (prices[prices.size() - 1] > prices[prices.size() - 2])
		ret += prices[prices.size() - 1] - minp;
	return ret;
}
