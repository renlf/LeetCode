#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void bt_wordBreak(vector<string> & ret, vector<string> &sub_ret, vector<vector<bool>> dp, string s, int pos)
{
	if (pos == 0)
	{
		string new_str = "";
		for (auto iter = sub_ret.crbegin(); iter != sub_ret.crend(); iter++)
		{
			new_str += *iter;
			new_str += " ";
		}
		new_str.pop_back();
		ret.push_back(new_str);
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (dp[pos][i])
		{
			string tmp = s.substr(i, pos - i);
			sub_ret.push_back(tmp);
			bt_wordBreak(ret, sub_ret, dp, s, i);
			sub_ret.pop_back();
		}
	}
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	vector<bool> sub_dp(s.length() + 1, false);
	vector<vector<bool>> dp(s.length() + 1, vector<bool>(s.length(), false));
	sub_dp[0] = true;
	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (sub_dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end())
			{
				sub_dp[i] = true;
				dp[i][j] = true;
			}
		}
	}
	vector<string> ret;
	vector<string> sub_ret;
	bt_wordBreak(ret, sub_ret, dp, s, s.length());
	return ret;
}

void bt_wordBreak2(vector<string> & ret, string sub_ret, vector<vector<int>> dp, string s, int pos)
{
	if (pos == 0)
	{
		ret.push_back(sub_ret);
		return;
	}
	for (int i = 0; i < dp[pos].size(); i++)
	{
		string tmp = s.substr(dp[pos][i], pos - dp[pos][i]);
		if (pos == s.length())
			bt_wordBreak2(ret, tmp, dp, s, dp[pos][i]);
		else
			bt_wordBreak2(ret, tmp + " " + sub_ret, dp, s, dp[pos][i]);
	}
}

vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
	vector<bool> sub_dp(s.length() + 1, false);
	vector<vector<int>> dp(s.length() + 1);
	sub_dp[0] = true;
	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (sub_dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end())
			{
				sub_dp[i] = true;
				dp[i].push_back(j);
			}
		}
	}
	vector<string> ret;
	string sub_ret;
	bt_wordBreak2(ret, sub_ret, dp, s, s.length());
	return ret;
}
