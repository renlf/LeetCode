#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	int raw_len = matrix.size();
	int col_len = matrix[0].size();
	bool raw_empty = false;
	bool col_empty = false;
	for (int i = 0; i < raw_len; i++)
	{
		for (int j = 0; j < col_len; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
				if (i == 0)
					raw_empty = true;
				if (j == 0)
					col_empty = true;
			}
		}
	}
	for (int i = 1; i < raw_len; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j < col_len; j++)
				matrix[i][j] = 0;
		}
	}
	for (int i = 1; i < col_len; i++)
	{
		if (matrix[0][i] == 0)
		{
			for (int j = 0; j < raw_len; j++)
				matrix[j][i] = 0;
		}
	}
	if (raw_empty)
	{
		for (int i = 0; i < col_len; i++)
			matrix[0][i] = 0;
	}
	if (col_empty)
	{
		for (int i = 0; i < raw_len; i++)
			matrix[i][0] = 0;
	}
}

int main()
{
	vector < vector<int> > data = { {0, 1} };
	setZeroes(data);
	return 0;
}
