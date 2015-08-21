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
