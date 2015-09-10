#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int max_rect = 0;
	int raw_len = matrix.size();
	int col_len = matrix[0].size();
	vector<int> record(col_len + 2, 0);
	record[0] = -1;
	for (int i = 0; i < raw_len; i++)
	{
		stack<int> st;
		st.push(0);
		for (int j = 0; j < col_len + 1; j++)
		{
			if (j < col_len)
			{
				if (matrix[i][j] == '1')
					record[j + 1]++;
				else
					record[j + 1] = 0;
			}
			while (!st.empty() && record[j + 1] <= record[st.top()])
			{
				int h = record[st.top()];
				st.pop();
				int tmp_rect = h * (j - st.top());
				max_rect = max(max_rect, tmp_rect);
			}
			st.push(j + 1);
		}
	}
	return max_rect;
}

int main()
{
	vector<vector<char>> matrix = { { '0', '1', '1', '1' } };
	int ret = maximalRectangle(matrix);
	return 0;
}
