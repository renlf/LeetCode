#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> next_str(string cur, unordered_set<string> &wordList)
{
	vector<string> ret;
	for (int i = 0; i < cur.length(); i++)
	{
		char tmp = cur[i];
		for (int j = 0; j < 26; j++)
		{
			if (cur[i] == 'a' + j)
				continue;

			cur[i] = 'a' + j;
			if (wordList.count(cur))
			{
				ret.push_back(cur);
				wordList.erase(cur);
			}
		}
		cur[i] = tmp;
	}
	return ret;
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	wordList.insert(endWord);
	queue<pair<string, int>> que;
	que.push(pair<string, int>(beginWord, 1));
	while (!que.empty())
	{
		string cur = que.front().first;
		int len = que.front().second;
		if (cur == endWord)
			return len;
		que.pop();
		vector<string> next = next_str(cur, wordList);
		for (int i = 0; i < next.size(); i++)
		{
			que.push(pair<string, int>(next[i], len + 1));
		}
	}
	return 0;
}
