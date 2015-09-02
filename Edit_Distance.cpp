#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
	if (word1.size() == 0 || word2.size() == 0)
		return word1.size() + word2.size();
	vector<vector<int>> dp;
	dp.resize(word1.size() + 1, vector<int>(word2.size() + 1));	
	dp[0][0] = 0;
	for(int i = 1;  i <= word1.size(); i++)
	{
		dp[i][0] = i;
	}
	for(int i = 1;  i <= word2.size(); i++)
	{
		dp[0][i] = i;
	}
	for(int i = 0; i < word1.size(); i++)
	{
		for(int j =0; j < word2.size(); j++)
		{
			if(word1[i] == word2[j])
				dp[i+1][j+1] = dp[i][j];
			else
			{
				dp[i+1][j+1] = min(min(dp[i][j], dp[i+1][j]), dp[i][j+1]) + 1;
			}
		}
	}
	return dp[word1.size()][word2.size()];
}

int minDistance2(string word1, string word2)
{
	int len_1 = word1.size();
	int len_2 = word2.size();
	if (len_1 == 0 || len_2 == 0)
		return len_1 + len_2;
	vector<int> dp;
	dp.resize(len_1 + 1, 0);
	for (int i = 1; i <= len_1; i++)
		dp[i] = i;
	for (int i = 1; i <= len_2; i++)
	{
		int pre = dp[0];
		dp[0] = i;
		for (int j = 1; j <= len_1; j++)
		{
			int tmp = dp[j];
			if (word1[j - 1] == word2[i - 1])
				dp[j] = pre;
			else
				dp[j] = min(pre, min(dp[j], dp[j - 1])) + 1;
			pre = tmp;
		}
	}
	return dp[len_1];
}

int main()
{
	int ret = minDistance("", "a");
	return 0;
}
