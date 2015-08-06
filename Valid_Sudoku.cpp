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
