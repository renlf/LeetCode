#include <vector>

using namespace std;

int numTrees(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int left = 0; left < i; left++)
		{
			dp[i] += (dp[left] * dp[i - 1 - left]);
		}
	}
	return dp[n];
}
