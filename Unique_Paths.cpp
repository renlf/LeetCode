#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
	vector<vector<int>> dp;
	dp.resize(m, vector<int>(n));
	for (int i = 1; i < m; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 1; j < n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	return dp[m-1][n-1];
}

int main()
{
	int result = uniquePaths(1, 2);
	return 0;
}
