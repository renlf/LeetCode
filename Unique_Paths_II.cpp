#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.size() == 0)
		return 0;
	int m_len = obstacleGrid.size();
	int n_len = obstacleGrid[0].size();
	if (obstacleGrid[0][0] == 1 || obstacleGrid[m_len - 1][n_len - 1] == 1)
		return 0;
	vector<vector<int>> dp;
	dp.resize(m_len, vector<int>(n_len));
	dp[0][0] = 1;
	bool is_obstacle = false;
	for (int i = 1; i < m_len; i++)
	{
		if (obstacleGrid[i - 1][0] == 1)
			dp[i][0] = 0;
		else
			dp[i][0] = dp[i - 1][0];
	}
	for (int j = 1; j < n_len; j++)
	{
		if (obstacleGrid[0][j - 1] == 1)
			dp[0][j] = 0;
		else
			dp[0][j] = dp[0][j - 1];
	}
	for (int i = 1; i < m_len; i++)
	{
		for (int j = 1; j < n_len; j++)
		{
			dp[i][j] = 0;
			if (obstacleGrid[i - 1][j] == 0)
				dp[i][j] += dp[i - 1][j];
			if (obstacleGrid[i][j - 1] == 0)
				dp[i][j] += dp[i][j - 1];
		}
	}
	return dp[m_len - 1][n_len - 1];
}
