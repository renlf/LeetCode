#include <iostream>
#include <vector>
#include <string>

using namespace std;

void step_combine(vector<string> &result, vector<string> letters, vector<int> &index, vector<int> full_index,int depth)
{
	if (depth == index.size())
	{
		string tmp_result = "";
		for (int i = 0; i < depth; i++)
		{
			tmp_result.append(1, letters[full_index[i]][index[i]]);
		}
		 result.push_back(tmp_result);
		 return;
	}
	for (int j = 0; j < letters[full_index[depth]].size(); j++)
	{
		index[depth] = j;
		step_combine(result, letters, index, full_index, depth + 1);
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> Letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
	vector<string> result;
	vector<int> index;
	for (int i = 0; i < digits.size(); i++)
	{
		int tmp = digits[i] - '0';
		if (tmp != 0 && tmp != 1)
		{
			index.push_back(tmp);
		}
	}
	if (index.size() == 0)
		return result;
	vector<int> path_index;
	path_index.resize(digits.size(), 0);
	step_combine(result, Letters, path_index, index, 0);
	return result;
}

int main()
{
	string digit = "23";
	vector<string> result;
	result = letterCombinations(digit);
	return 0;
}
