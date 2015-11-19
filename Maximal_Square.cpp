#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int M = matrix.size();
		int N = matrix[0].size();
		vector<vector<int>> dp(M, vector<int>(N, 0));
		int ret = 0;
		for (int i = 0; i < M; i++)
		{
			if (matrix[i][0] == '1')
			{
				dp[i][0] = 1;
				ret = 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if (matrix[0][i] == '1')
			{
			    dp[0][i] = 1;
			    ret = 1;
			}
		}
		for (int i = 1; i < M; i++)
		{
			for (int j = 1; j < N; j++)
			{
			    if (matrix[i][j] == '1')
				{
				    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				    ret = max(dp[i][j], ret);
				}
			}
		}
		return ret * ret;
	}
};
