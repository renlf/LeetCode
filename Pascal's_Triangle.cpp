#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	if (numRows == 0)
		return ret;
	
	for (int i = 0; i <= numRows; i++)
	{
		vector<int> sub_ret;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				sub_ret.push_back(1);
			else if (j == i)
				sub_ret.push_back(1);
			else
			{
				int val = ret[i-1][i-1]+ret[i-1][i-2];
				sub_ret.push_back(val);
			}
		}
		ret.push_back(sub_ret);
	}
	return ret;
}
