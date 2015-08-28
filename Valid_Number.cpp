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
	bool former_num = false;
	bool backer_num = false;
	while (iter < s.length() && (s[iter] - '0' >= 0 && s[iter] - '0' <= 9))
	{
		iter++;
		former_num = true;
	}
	int de_cpy = iter + 1;
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
		former_num = true;
	}

	backer_num = false;
	if (former_num && s[iter] == 'e')
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

bool isNumber2(string s)
{
	if (s.length() == 0)
		return false;
	int former = 0;
	int backer = s.length() - 1;
	while (s[former] == ' ')
		former++;
	while (s[backer] == ' ')
		backer--;
	if (s[former] == '+' || s[former] == '-')
		former++;
	bool is_dot = false;
	bool is_exp = false;
	bool is_lft = false;
	bool is_rht = false;
	while (former <= backer)
	{
		if (s[former] == '.')
		{
			if (is_dot || is_rht || is_exp)
				return false;
			is_dot = true;
		}
		else if (s[former] == 'e')
		{
			if (is_exp || !is_lft)
				return false;
			is_exp = true;
		}
		else if (s[former] == '+' || s[former] == '-')
		{
			if (s[former - 1] != 'e')
				return false;
		}
		else if ((s[former] - '0' >= 0) && (s[former] - '0' <= 9))
		{
			if (is_exp)
				is_rht = true;
			else
				is_lft = true;
		}
		else
		{
			return false;
		}
		former++;
	}
	if (!is_lft || (is_exp && !is_rht))
		return false;
	return true;	
}

int main()
{
	string s = ".2e3";
	bool ret = isNumber(s);
	return 0;
}
