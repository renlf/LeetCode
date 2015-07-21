#include <string>
#include <vector>

using namespace std;

void step_generate(vector<string> &result, string tmp_result, int m, int n)
{
	if (n == 0)
	{
		while (m > 0)
		{
			tmp_result += ")";
			m--;
		}
		result.push_back(tmp_result);
		return;
	}
	if (m == 0)
	{
		tmp_result += "(";
		step_generate(result, tmp_result, m + 1, n - 1);
	}
	else
	{
		string tmp_copy = tmp_result;
		tmp_result += ")";
		step_generate(result, tmp_result, m - 1, n);
		tmp_copy += "(";
		step_generate(result, tmp_copy, m + 1, n - 1);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	string tmp_result = "";
	step_generate(result, tmp_result, 0, n);
	return result;
}

int main()
{
	vector<string> result = generateParenthesis(3);
	return 0;
}
