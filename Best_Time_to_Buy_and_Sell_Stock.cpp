#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() == 0)
		return 0;
	int ret = 0;
	int minp = prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < minp)
			minp = prices[i];
		else
			ret = max(ret, prices[i] - minp);
	}
	return ret;
}
