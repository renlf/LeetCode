#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
	char p[6] = { '(', ')', '{', '}', '[', ']' };
	stack<int> container;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == p[0] || s[i] == p[2] || s[i] == p[4])
		{
			container.push(s[i]);
		}
		else
		{
			if (container.empty() == true)
				return false;
			char tmp_p = container.top();
			if ((tmp_p == p[0] && s[i] == p[1]) || (tmp_p == p[2] && s[i] == p[3]) || (tmp_p == p[4] && s[i] == p[5]))
				container.pop();
			else
				return false;

		}
	}
	if (container.empty() == false)
	{
		return false;
	}
	return true;
}

int main()
{
	string s = "]";
	isValid(s);
	return 0;
}
