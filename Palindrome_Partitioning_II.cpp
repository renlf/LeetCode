#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minCut(string s) {
	int len = s.length();
	vector<vector<bool>> is_pal(len, vector<bool>(len, false));
	vector<int> steps(len);
	for (int i = 0; i < len; i++)
	{
		steps[i] = i;
		for (int j = 0; j <= i; j++)
		{
			if (s[i] == s[j] && (i - j < 2 || is_pal[j + 1][i - 1]))
			{
				is_pal[j][i] = true;
				if (j == 0)
				{
					steps[i] = 0;
				}
				else
				{
					steps[i] = min(steps[i], steps[j - 1] + 1);
				}
			}
		}
	}
	return steps[len - 1];
}
