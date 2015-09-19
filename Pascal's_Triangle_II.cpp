#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> ret;
	for (int i = 0; i <= rowIndex; i++)
	{
		if (i <= 1)
			ret.push_back(1);
		else
		{
			ret.push_back(1);
			int backer = ret[0];
			for (int j = 1; j <= i / 2; j++)
			{
				int fs = ret[j];
				ret[j] = fs + backer;
				ret[i - j] = ret[j];
				backer = fs;
			}			
		}
	}
	return ret;
}
