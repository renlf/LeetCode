#include <vector>

using namespace std;

bool bt_exit(vector<vector<char>>& board, vector<vector<bool>> & visited, int x, int y, string word, int pos)
{
	if (pos == word.length())
		return true;
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y])
		return false;
	if (word[pos] != board[x][y])
		return false;
	visited[x][y] = true;
	if (bt_exit(board, visited, x - 1, y, word, pos + 1))
		return true;
	if (bt_exit(board, visited, x + 1, y, word, pos + 1))
		return true;
	if (bt_exit(board, visited, x, y - 1, word, pos + 1))
		return true;
	if (bt_exit(board, visited, x, y + 1, word, pos + 1))
		return true;
	visited[x][y] = false;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	vector<vector<bool>> visited;
	visited.resize(board.size(), vector<bool>(false));
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (bt_exit(board, visited, i, j, word, 0))
				return true;
		}
	}
	return false;
}


bool bt_exit2(vector<vector<char>> &board, int x, int y, string word, int pos)
{
	if (pos == word.size())
		return true;
	if (x < 0 || y < 0 || x == board.size() || y == board[0].size())
		return false;
	if (word[pos] != board[x][y])
		return false;
	char tmp = board[x][y];
	board[x][y] = '\0';
	bool ret = bt_exit2(board, x - 1, y, word, pos + 1) ||
		bt_exit2(board, x + 1, y, word, pos + 1) ||
		bt_exit2(board, x, y - 1, word, pos + 1) ||
		bt_exit2(board, x, y + 1, word, pos + 1);
	board[x][y] = tmp;
	return ret;
}

bool exist2(vector<vector<char>>& board, string word) {
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (bt_exit2(board, i, j, word, 0))
				return true;
		}
	}
	return false;
}
