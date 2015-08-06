#include <vector>
#include <unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, bool> record;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (!record[board[i][j] - '0'])
                    record[board[i][j] - '0'] = 1;
                else
                    return false;
            }
        }
        record.clear();
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] != '.')
            {
                if (!record[board[j][i] - '0'])
                    record[board[j][i] - '0'] = 1;
                else
                    return false;
            }
        }
        record.clear();
    }
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    if (board[x][y] != '.')
                    {
                        if (!record[board[x][y] - '0'])
                            record[board[x][y] - '0'] = 1;
                        else
                            return false;
                    }
                }
            }
            record.clear();
        }
    }
	return true;
}

bool isValid(unordered_map<int, bool> &record, vector<vector<char>>& board, int i, int j)
{
	if (board[i][j] != '.')
	{
	    if (record[board[i][j] - '0'])
			return false;
		else
			record[board[i][j] - '0'] = 1;
	}
	return true;
}

bool isValidSudoku2(vector<vector<char>>& board) {
    unordered_map<int, bool> raw;
    unordered_map<int, bool> col;
    unordered_map<int, bool> sub;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
			if (!isValid(raw, board, i, j) || !isValid(col, board, j, i) || !isValid(sub, board, 3 * (i / 3) + j / 3, 3 * (i % 3) + j % 3))
				return false;
        }
        raw.clear();
        col.clear();
        sub.clear();
    }
    return true;
}

int main()
{
	vector<string> data = {".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........"};
	vector<vector<char>> c_data;
	for (int i = 0; i < 9; i++)
	{
		string tmp = data[i];
		vector<char> tc_data;
		for (int j = 0; j < 9; j++)
		{
			tc_data.push_back(tmp[j]);
		}
		c_data.push_back(tc_data);
	}

	bool result = isValidSudoku2(c_data);
	return 0;
}
