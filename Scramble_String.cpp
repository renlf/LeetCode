#include <string>
#include <unordered_map>

using namespace std;

bool isScramble(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	if (s1 == s2)
		return true;
	int record[26];
	memset(record, 0, 26 * sizeof(record[0]));
	for (int i = 0; i < s1.size(); i++)
	{
		record[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		record[s2[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (record[i] != 0)
			return false;
	}
	for (int i = 1; i < s1.length(); i++)
	{
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s1.size() - i)))
			return true;
		if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s1.size() - i)))
			return true;
	}
	return false;
}

bool isScramble2(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	if (s1 == s2)
		return true;
	int len = s1.length();
	vector<vector<vector<bool>>> dp(len + 1, vector<vector<bool>>(len, vector<bool>(len, false)));
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (s1[i] == s2[j])
				dp[1][i][j] = true;
		}
	}
	for (int n = 1; n <= len; n++)
	{
		for (int i = 0; i <= len - n; i++)
		{
			for (int j = 0; j <= len - n; j++)
			{
				for (int k = 1; k < n; k++)
				{
					if ((dp[k][i][j] && dp[n-k][i + k][j + k]) || (dp[k][i][j + n - k] && dp[n - k][i+k][j]))
					{
						dp[n][i][j] = true;
						break;
					}
				}
			}
		}
	}
	return dp[len][0][0];
}

int main()
{
	bool ret = isScramble("abcdefghijklmn", "efghijklmncadb");
	return 0;
}
