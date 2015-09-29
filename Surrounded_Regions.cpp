#include <vector>
#include <queue>

using namespace std;

void solve(vector<vector<char>>& board) {
	if (board.size() < 3 || board[0].size() < 3)
		return;
	queue<pair<int, int>> que;
	int r_len = board.size();
	int c_len = board[0].size();
	for (int i = 0; i < r_len; i++)
	{
		if (board[i][0] == 'O')
			que.push(make_pair(i, 0));
		if (board[i][c_len - 1] == 'O')
			que.push(make_pair(i, c_len - 1));
	}

	for (int i = 0; i < c_len; i++)
	{
		if (board[0][i] == 'O')
			que.push(make_pair(0, i));
		if (board[r_len - 1][i] == 'O')
			que.push(make_pair(r_len - 1, i));
	}

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		board[x][y] = 'A';
		if (x > 0 && board[x - 1][y] == 'O')
			que.push(make_pair(x - 1, y));
		if (x < r_len - 1 && board[x + 1][y] == 'O')
			que.push(make_pair(x + 1, y));
		if (y > 0 && board[x][y - 1] == 'O')
			que.push(make_pair(x, y - 1));
		if (y < c_len - 1 && board[x][y + 1] == 'O')
			que.push(make_pair(x, y + 1));
	}
	for (int i = 0; i < r_len; i++)
	{
		for (int j = 0; j < c_len; j++)
		{
			if (board[i][j] == 'O')
				board[i][j] = 'X';
			if (board[i][j] == 'A')
				board[i][j] = 'O';
		}
	}
}

int main()
{
	vector<vector<char>> board = { { 'X', 'X', 'X' }, { 'X', 'O', 'X' }, { 'X', 'X', 'X' } };
	solve(board);
	return 0;
}
