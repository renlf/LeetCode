#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	if (matrix.size() <= 1)
		return;
	int len = matrix.size();
	for (int i = 0; i < len / 2; i++)
	{
		for (int j = 0; j < ceil((double)len / 2); j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[len - 1 - j][i];
			matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
			matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
			matrix[j][len - 1 - i] = tmp;
		}
	}
}

int main()
{
	vector<vector<int>> data;
	for (int i = 0; i < 5; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < 5; j++)
	{	
			tmp.push_back(i + j);
		}
		data.push_back(tmp);
	}
	rotate(data);
	return 0;
}
