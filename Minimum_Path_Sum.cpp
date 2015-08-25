#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	vector<vector<int>> dp;
	int m_len = grid.size();
	int n_len = grid[0].size();
	dp.resize(m_len, vector<int>(n_len));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < m_len; i++)
	{
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	for (int i = 1; i < n_len; i++)
	{
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	}

	for (int i = 1; i < m_len; i++)
	{
		for (int j = 1; j < n_len; j++)
		{
			dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m_len - 1][n_len - 1];
}

int main()
{
	vector<vector<int>> grid = { { 0, 1 }, {1,0} };
	int ret = minPathSum(grid);
	return 0;
}
