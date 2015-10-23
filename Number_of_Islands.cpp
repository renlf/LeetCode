#include <vector>

using namespace std;

class Solution {
private:
	void bt_islands(vector<vector<char>>& grid, int i, int j)
	{
		if (j > 0 && grid[i][j - 1] == '1')
		{
			grid[i][j - 1] = '*';
			bt_islands(grid, i, j - 1);
		}
		if (j < grid[i].size() - 1 && grid[i][j + 1] == '1')
		{
			grid[i][j + 1] = '*';
			bt_islands(grid, i, j + 1);
		}
		if (i > 0 && grid[i - 1][j] == '1')
		{
			grid[i - 1][j] = '*';
			bt_islands(grid, i - 1, j);
		}
		if (i < grid.size() - 1 && grid[i + 1][j] == '1')
		{
			grid[i + 1][j] = '*';
			bt_islands(grid, i + 1, j);
		}
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int ret = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					grid[i][j] = '*';
					bt_islands(grid, i, j);
					ret++;
				}
			}
		}
		return ret;
	}
};
