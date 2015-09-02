#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int raw_len = matrix.size();
	int col_len = matrix[0].size();

	int backer = 0;
	int former = raw_len * col_len - 1;
	while (backer <= former)
	{
		int mid = (backer + former) / 2;
		int new_raw = mid / col_len;
		int new_col = mid % col_len;
		if (matrix[new_raw][new_col] == target)
			return true;
		else if (matrix[new_raw][new_col] > target)
		{
			former = mid - 1;
		}
		else
		{
			backer = mid + 1;
		}
	}
	return false;
}

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
	int raw_len = matrix.size();
	int col_len = matrix[0].size();
	if (target < matrix[0][0] || target > matrix[raw_len - 1][col_len - 1])
		return false;
	int backer = 0;
	int former = raw_len - 1;
	while (backer <= former)
	{
		int mid = (backer + former) / 2;
		if (matrix[mid][0] == target)
			return true;
		else if (matrix[mid][0] > target)
			former = mid - 1;
		else
			backer = mid + 1;
	}
	int traw = former;
	former = col_len - 1;
	backer = 0;
	while (backer <= former)
	{
		int mid = (backer + former) / 2;
		if (matrix[traw][mid] == target)
			return true;
		else if (matrix[traw][mid] > target)
			former = mid - 1;
		else
			backer = mid + 1;
	}
	return false;
}

int main()
{
	vector<vector<int>> data = { {1, 1} };
	bool ret = searchMatrix(data, 2);
	return 0;
}
