#include <string>
#include <vector>

using namespace std;

int numDecodings(string s) {
	if (s.length() == 0 || (s.length() > 0 && s[0] == '0'))
		return 0;
	vector<int> dp(s.length() + 1, 1);
	for (int i = 2; i <= s.length(); i++)
	{
		if (s[i - 1] != '0')
			dp[i] = dp[i - 1];
		else
			dp[i] = 0;
		int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
		if (val >= 10 && val <= 26)
			dp[i] += dp[i - 2];
	}
	return dp[s.length()];
}
