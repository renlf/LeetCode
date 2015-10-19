#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int N = dungeon.size();
	int M = dungeon[0].size();
	vector<vector<int>> dp(N+1, vector<int>(M+1, INT_MAX));
	dp[N - 1][M] =  dp[N][M-1] = 1;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = M - 1; j >= 0; j--)
		{
			int hp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
			dp[i][j] = max(1, hp);
		}
	}
	return dp[0][0];
}

int calculateMinimumHP2(vector<vector<int>>& dungeon) {
	int N = dungeon.size();
	int M = dungeon[0].size();
	vector<int> dp(M + 1, INT_MAX);
	dp[M - 1] = 1;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = M - 1; j >= 0; j--)
		{
			int hp = min(dp[j], dp[j + 1]) - dungeon[i][j];
			dp[j] = max(1, hp);
		}
	}
	return dp[0];
}
