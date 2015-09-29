#include <vector>
#include <string>

using namespace std;

void bt_partition(vector<vector<string>> &ret, vector<string> &sub_ret, string s, vector<vector<bool>> is_pal,int start)
{
	if (start == s.length())
	{
		ret.push_back(sub_ret);
		return;
	}
	for (int i = start; i < s.length(); i++)
	{		
		if (is_pal[start][i])
		{
			string tmp = s.substr(start, i - start + 1);
			sub_ret.push_back(tmp);
			bt_partition(ret, sub_ret, s, is_pal, i + 1);
			sub_ret.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	int len = s.length();
	vector<vector<bool>> is_pal(len, vector<bool>(len, false));
	for (int i = 0; i < len; i++)
	{		
		for (int j = 0; j <= i; j++)
		{
			is_pal[j][i] = (s[i] == s[j] && (i - j < 2 || is_pal[j + 1][i - 1]));
		}
	}

	vector<vector<string>> ret;
	vector<string> sub_ret;
	bt_partition(ret, sub_ret, s, is_pal, 0);
	return ret;
}

int main()
{
	string s = "amanaplanacanalpanama";
	vector<vector<string>> ret = partition(s);
	return 0;
}
