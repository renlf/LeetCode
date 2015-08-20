#include <vector>
#include <string>

using namespace std;

int max_index = 0;
string no_queens = "";

void Queens(vector<vector<string>> &ret, vector<string> sub_ret, int raw, int left, int right)
{
	if (raw == max_index)
	{
		if (sub_ret.size() == no_queens.length())
			ret.push_back(sub_ret);
		return;
	}
	int index = max_index & (~(raw | left | right));
	while (index > 0)
	{
		int next = index & (-index);
		int pos = 0;
		while (next > 1)
		{
			if (next & 1)
				break;
			next = next >> 1;
			pos++;
		}
		next = index & (-index);
		no_queens[pos] = 'Q';
		sub_ret.push_back(no_queens);
		no_queens[pos] = '.';
		Queens(ret, sub_ret, (raw + next), (left + next) << 1, (right + next) >> 1);
		sub_ret.pop_back();		
		index -= next;
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ret;
	vector<string> sub_ret;
	max_index = (1 << n) - 1;
	for (int i = 0; i < n; i++)
		no_queens.push_back('.');
	Queens(ret, sub_ret, 0, 0, 0);
	return ret;
}

int main()
{
	vector<vector<string>> ret = solveNQueens(4);
	return 0;
}
