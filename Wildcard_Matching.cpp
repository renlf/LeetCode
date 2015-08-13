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
		for (int i = 0; i < s.length(); i++)
		{
			if (isMatch(s.substr(i, s.length() - i), p.substr(pos, p.length() - pos)))
				return true;
		}
		return false;
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

int main()
{
	string s = "bbbaaabaababbabbbaabababbbabababaabbaababbbabbbabb"; 
	string p = "*b**b***baba***aaa*b***";
	bool result = isMatch(s, p);
	return 0;
}
