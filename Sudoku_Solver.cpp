#include <vector>
#include <unordered_map>

using namespace std;

void eraseElement(unordered_map<char, bool> &remain, char el, int x, int y)
{
	unordered_map<char, bool>::iterator iter = remain.find(el);
	if (iter != remain.end())
		remain.erase(iter);
}

unordered_map<char, bool> findRemain(vector<vector<char>> board, int x, int y)
{
	unordered_map<char, bool> remain;
	for (int i = 1; i <= 9; i++)
		remain['0' + i] = 1;
	
	for (int i = 0; i < 9 && !remain.empty(); i++)
	{
		if (i != y && board[x][i] != '.')
			eraseElement(remain, board[x][i], x, i);

		if (i != x && board[i][y] != '.')
			eraseElement(remain, board[i][y], i, y); 

		int index_x = 3* (x / 3) + i / 3;
		int index_y =  3 * (y / 3) + i % 3;

		if (index_x != x && index_y != y && board[index_x][index_y] != '.')
			eraseElement(remain, board[index_x][index_y], index_x, index_y);
	}
	return remain;
}

bool solveCell(vector<vector<char>> & board, int x, int y)
{
	if (x == 9)
		return true;
	int next_x = x + y / 8;
	int next_y = (y + 1) % 9;
	if (board[x][y] != '.')
	{
		return solveCell(board, next_x, next_y);
	}
	else
	{
		unordered_map<char, bool> remain = findRemain(board, x, y);
		if (remain.empty())
		{
			return false;
		}
		unordered_map<char, bool>::iterator iter = remain.begin();
		while (iter != remain.end())
		{
			board[x][y] = iter->first;
			if (solveCell(board, next_x, next_y))
				return true;
			iter++;
		}
		board[x][y] = '.';
		return false;
	}
}

void solveSudoku(vector<vector<char>>& board) {
	solveCell(board, 3 , 1);
}

int main()
{
	vector<string> data = { "53..7....", 
							"6..195...",
							".98....6.", 
							"8...6...3",
							"4..8.3..1", 
							"7...2...6", 
							".6....28.", 
							"...419..5", 
							"....8..79" };
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
	
	//unordered_map<char, bool> remain = findRemain(c_data,  3, 3);
	solveSudoku(c_data);
	return 0;
}