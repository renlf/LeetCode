#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t) {
	if (s.length() < t.length())
		return 0;
	int s_len = s.length();
	int t_len = t.length();
	vector<vector<int>> dp(s_len + 1, vector<int>(t_len + 1, 0));
	for (int i = 0; i < s_len; i++)
	{
		if (s[i] == t[0])
			dp[i][0] = 1;
	}
	for (int i = 1; i <= s_len; i++)
	{
		for (int j = 1; j <= i && j <= t_len; j++)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] += dp[i - 1][j - 1];
			if (i > j)
				dp[i][j] += dp[i - 1][j];
		}
	}
	return dp[s_len][t_len];
}

int numDistinct2(string s, string t) {
	if (s.length() < t.length())
		return 0;
	int s_len = s.length();
	int t_len = t.length();
	vector<int> dp(t_len + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= s_len; i++)
	{
		for (int j = t_len; j >= 1; j--)
		{
			if (s[i - 1] == t[j - 1])
				dp[j] += dp[j - 1];
		}
	}
	return dp[t_len];
}

int main()
{
	int ret = numDistinct("rabbbit", "rabbit");
	return 0;
}
