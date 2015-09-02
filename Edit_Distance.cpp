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

int main()
{
	int ret = minDistance("", "a");
	return 0;
}
