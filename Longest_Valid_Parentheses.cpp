#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
	if (s.size() <= 1)
	{
		return 0;
	}
	int left = 0;
	int right = s.size() - 1;
	if (s[left] == '(' && s[right] == ')')
	{
		if (left + 1 < s.size() && s[left + 1] == ')')
		{
			return longestValidParentheses(s.substr(left + 2, right - left - 1)) + 1;
		}
		else if (right - 1 >= 0 && s[right - 1] == '(')
		{
			return longestValidParentheses(s.substr(left, right - left - 1)) + 1;
		}
		else
			return longestValidParentheses(s.substr(left + 1, right - left - 1)) + 1;
	}
	else
		return max(longestValidParentheses(s.substr(left + 1, right - left)), longestValidParentheses(s.substr(left, right - left)));
}


int longestValidParentheses2(string s) {
	if (s.size() <= 1)
	{
		return 0;
    }
    stack<char> match;
    stack<int> pos;
	int result = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            match.push(s[i]);
            pos.push(i);
        }
        else
        {
            if(!match.empty() && match.top() == '(')
            {
                match.pop();
                pos.pop();
				result = max(result, (pos.empty() ? i + 1 : i - pos.top()));
            }
            else
            {
                match.push(s[i]);
                pos.push(i);
            }
        }
    }
    return result;
}
int main()
{
	string s = "(((((((()";
	int result = longestValidParentheses2(s);
	return 0;
}
