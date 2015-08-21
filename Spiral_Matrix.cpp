#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ret;
	if (matrix.size() == 0)
		return ret;
	if (matrix.size() == 1)
		return matrix[0];

	int matrix_count = matrix.size() * matrix[0].size();
	int up = 0;
	int down = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;

	int i = 0;
	int j = 0;
	while (ret.size() < matrix_count)
	{
		i = up;
		j = left;
		while (j <= right)
		{
			ret.push_back(matrix[up][j]);
			j++;
		}
		up++;
		i = up;
		j -= 2;

		if (ret.size() < matrix_count && up <= down)
		{
			while (i <= down)
			{
				ret.push_back(matrix[i][right]);
				i++;
			}
			if (right != left)
				right--;
			i -= 2;
		}

		if (ret.size() < matrix_count && left <= right)
		{
			while (j >= left)
			{
				ret.push_back(matrix[down][j]);
				j--;
			}
			down--;
		}

		if (ret.size() < matrix_count && up <= down)
		{
			while (i >= up)
			{
				ret.push_back(matrix[i][left]);
				i--;
			}
			left++;
		}
	}
	return ret;
}

vector<int> spiralOrder2(vector<vector<int>>& matrix)
{
	vector<int> ret;
	if (matrix.size() == 0)
		return ret;
	if (matrix.size() == 1)
		return matrix[0];

	int up = 0;
	int down = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;

	while (up < down && left < right)
	{
		for (int i = left; i <= right; i++)
			ret.push_back(matrix[up][i]);
		for (int j = ++up; j <= down; j++)
			ret.push_back(matrix[j][right]);
		for (int m = --right; m >= left; m--)
			ret.push_back(matrix[down][m]);
		for (int n = --down; n >= up; n--)
			ret.push_back(matrix[n][left]);
		left++;
	}
	if (up == down)
	{
		for (int j = left; j <= right; j++)
			ret.push_back(matrix[up][j]);
	}
	else if (left == right)
	{
		for (int i = up; i <= down; i++)
			ret.push_back(matrix[i][left]);
	}
	return ret;
}

int main()
{
	vector<vector<int>> matrix;
	int num = 1;
	for (int i = 0; i < 3; i++)
	{
		vector<int> data;
		for (int j = 0; j < 3; j++)
		{
			data.push_back(num);
			num++;
		}
		matrix.push_back(data);
	}
	vector<vector<int>> tmp = { { 7 }, { 9 }, {6} };
	vector<int> ret = spiralOrder(tmp);
	return 0;
}
