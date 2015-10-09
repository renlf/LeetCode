#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

int evalRPN(vector<string>& tokens) {
	int ret = 0;
	stack<int> nums;
	unordered_set<string> op = { "+", "-", "*", "/" };
	for (int i = 0; i < tokens.size(); i++)
	{
		string tmp = tokens[i];

		if (op.find(tmp) == op.end())
		{
			nums.push(stoi(tmp));
		}
		else
		{
			int val1 = nums.top();
			nums.pop();
			int val2 = nums.top();
			nums.pop();
			if (tmp == "+")
			{
				nums.push(val2 + val1);
			}
			else if (tmp == "-")
			{
				nums.push(val2 - val1);
			}
			else if (tmp == "*")
			{
				nums.push(val2 * val1);
			}
			else
			{
				nums.push(val2 / val1);
			}
		}
	}
	if (!nums.empty())
		ret = nums.top();
	return ret;
}
