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
	int slen = strlen(s), plen = strlen(p);
	vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= plen; i++)
		dp[0][i] = dp[0][i - 1] && (p[i - 1] == '*');
	for (int i = 1; i <= slen; i++)
		dp[i][0] = false;
	for (int i = 1; i <= slen; i++)
	{
		for (int j = 1; j <= plen; j++)
		{
			if (p[j - 1] != '*')
				dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
			else
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; //Note here that if p[j-1] == '*', then p[j-1] can either match empty string or match s[i-1] in such case,p[i-1] should keep matching forward.
		}
	}
	bool ret = dp[slen][plen];
	return ret;
}

int main()
{
	string s = "bbbaaabaababbabbbaabababbbabababaabbaababbbabbbabb"; 
	string p = "*b**b***baba***aaa*b***";
	bool result = isMatch(s, p);
	return 0;
}
