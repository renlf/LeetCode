#include <string>

using namespace std;

bool isNumber(string s) {
	if (s.length() == 0)
		return false;
	int iter = 0;
	while (s[iter] == ' ')
		iter++;
	if (iter < s.length() && (s[iter] == '+' || s[iter] == '-'))
	{
		iter++;
	}
	if (iter == s.length())
		return false;
	int iter_cpy = iter;
	bool former_num = false;
	while (iter < s.length() && (s[iter] - '0' >= 0 && s[iter] - '0' <= 9))
	{
		iter++;
		former_num = true;
	}
	if (iter == s.length())
		return true;
	int de_cpy = iter + 1;
	bool backer_num = false;
	if (s[iter] == '.')
	{
		iter++;
		while (iter < s.length() && (s[iter] - '0' >= 0 && s[iter] - '0' <= 9))
		{
			iter++;
			backer_num = true;
		}
		if (!former_num && !backer_num)
			return false;

	}
	former_num = true;
	backer_num = false;
	if (iter_cpy != iter && s[iter] == 'e')
	{
		iter++;
		int op_count = 0;
		while (iter < s.length() && ((s[iter] - '0' >= 0 && s[iter] - '0' <= 9) || s[iter] == '+' || s[iter] == '-'))
		{			
			if (s[iter] == '+' || s[iter] == '-')
			{
				backer_num = false;
				op_count++;
				if (op_count > 1)
					return false;
			}
			else
				backer_num = true;
			iter++;
		}
		if (!former_num || !backer_num)
			return false;
	}
	while (iter < s.length() && s[iter] == ' ')
		iter++;
	if (iter == s.length())
		return true;
	else
		return false;
}

int main()
{
	string s = ".2e3";
	bool ret = isNumber(s);
	return 0;
}
