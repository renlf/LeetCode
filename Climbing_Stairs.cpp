#include <vector>

using namespace std;

int climbStairs(int n) {
	if (n <= 2)
		return n;
	vector<int> dp;
	dp.resize(n);
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < n; i++)
	{
		dp[i] = dp[i - 1] + dp[i -2];
	}
	return dp[n - 1];
}

int climbStairs2(int n) {
	if (n <= 2)
		return n;
	int former = 1;
	int backer = 2;
	for (int i = 2; i < n; i++)
	{
		int tmp = backer;
		backer = backer + former;
		former = tmp;
	}
	return backer;
}
