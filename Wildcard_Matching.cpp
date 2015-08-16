#include <string>

using namespace std;

bool isMatch(string s, string p) {
	if (s.length() == 0 && p.length() == 0)
		return true;
	if (s.length() == 0 || p.length() == 0)
		return false;
	if (p[p.length() - 1] != '*' && p[p.length() - 1] != '?' && p[p.length() - 1] != s[s.length() - 1])
		return false;

	if (p[0] == '*')
	{
		int pos = 1;
		while (pos < p.length() && p[pos] == '*')
			pos++;
		if (pos == p.length())
			return true;
		return isMatch(s, p.substr(pos, p.length() - pos)) || isMatch(s.substr(1, s.length() - 1), p);
	}
	else if (p[0] == '?' || s[0] == p[0])
	{
		return isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
	}
	else
	{
		return false;
	}
}

bool isMatch2(const char *s, const char *p) {
	int s_len = s.length();
	int p_len = p.length();
	vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= s_len; i++)
		dp[i][0] = false;
	for (int i = 1; i <= p_len; i++)
		dp[0][i] = dp[0][i - 1] && (p[i - 1] == '*');

	for (int i = 1; i <= s_len; i++)
	{
		for (int j = 1; j <= p_len; j++)
		{
			if (p[j - 1] == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
		}
	}

	return dp[s_len][p_len];
}

bool isMatch3(string s, string p)
{
	int i = 0;
	int j = 0;
	int p_iter = -1;
	int s_iter = 0;
	while (i < s.length())
	{
		if (s[i] == p[j] || p[j] == '?')
		{
			i++;
			j++;
			continue;
		}
		if (p[j] == '*')
		{
			s_iter = i;
			p_iter = j++;
			continue;
		}
		if (p_iter != -1)
		{
			i = ++s_iter;
			j = p_iter + 1;
			continue;
		}
		return false;
	}
	while (j < p.length() && p[j] == '*')
		j++;
	if (j == p.length())
		return true;
	else
		return false;
}

int main()
{
	string s = "bbbaaabaababbabbbaabababbbabababaabbaababbbabbbabb"; 
	string p = "*b**b***baba***aaa*b***";
	bool result = isMatch(s, p);
	return 0;
}
