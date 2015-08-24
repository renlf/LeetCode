#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ret;
	ret.resize(n, vector<int>(n));
	int up = 0;
	int down = n - 1;
	int left = 0;
	int right = n - 1;
	int num = 1;
	for (int i = 0; i < ceil(n); i++)
	{
		for (int j = left; j <= right; j++)
		{
			ret[up][j] = num;
			num++;
		}
		for (int j = ++up; j <= down; j++)
		{
			ret[j][right] = num;
			num++;
		}
		for (int j = --right; j >= left; j--)
		{
			ret[down][j] = num;
			num++;
		}
		for (int j = --down; j >= up; j--)
		{
			ret[j][left] = num;
			num++;
		}
		left++;
	}
	return ret;
}

int main()
{
	vector<vector<int>> ret = generateMatrix(3);
	return 0;
}
