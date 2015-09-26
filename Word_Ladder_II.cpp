#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

void bt_find(vector<vector<string>> &ret, unordered_map<string, vector<string>> &root, vector<string> &sub_ret, const string &beginWord, const string &cur)
{
	sub_ret.push_back(cur);
	if (cur == beginWord)
	{
		ret.push_back(sub_ret);
		reverse(ret.back().begin(), ret.back().end());
	}
	else
	{
		for (const auto& x : root[cur])
		{
			bt_find(ret, root, sub_ret, beginWord, x);
		}
	}
	sub_ret.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
	vector<vector<string>> ret;
	if (beginWord == endWord || beginWord.length() != endWord.length())
		return ret;

	unordered_set<string> cur;
	unordered_set<string> next;
	unordered_set<string> flag;
	unordered_map<string, vector<string>> root;

	bool is_found = false;
	cur.insert(beginWord);
	while (!cur.empty() && !is_found)
	{
		for (const auto &x : cur)
			flag.insert(x);
		for (auto x : cur)
		{
			for (int i = 0; i < x.size(); i++)
			{

				for (char j = 'a'; j <= 'z'; j++)
				{
					if (x[i] == j)
						continue;
					string tmp = x;
					tmp[i] = j;
					if (tmp == endWord)
						is_found = true;
					if ((tmp == endWord || wordList.count(tmp) > 0) && flag.find(tmp) == flag.end())
					{
						next.insert(tmp);
						root[tmp].push_back(x);
					}
				}
			}
		}
		cur.clear();
		swap(cur, next);
	}
	if (is_found)
	{
		vector<string> sub_ret;
		bt_find(ret, root, sub_ret, beginWord, endWord);
	}
	return ret;
}


void gen_path(unordered_map<string, vector<string> > &father,
	vector<string> &path, const string &start, const string &word,
	vector<vector<string> > &result) {
	path.push_back(word);
	if (word == start) {
		result.push_back(path);
		reverse(result.back().begin(), result.back().end());
	}
	else {
		for (const auto& f : father[word]) {
			gen_path(father, path, start, f, result);
		}
	}
	path.pop_back();
}

vector<vector<string> > findLadders2(string start, string end,
	const unordered_set<string> &dict) {
	unordered_set<string> current, next;
	unordered_set<string> visited;
	unordered_map<string, vector<string> > father;

	bool found = false;

	auto state_is_target = [&](const string &s) {return s == end; };
	auto state_extend = [&](const string &s) {
		unordered_set<string> result;

		for (size_t i = 0; i < s.size(); ++i) {
			string new_word(s);
			for (char c = 'a'; c <= 'z'; c++) {
				if (c == new_word[i]) continue;

				swap(c, new_word[i]);

				if ((dict.count(new_word) > 0 || new_word == end) &&
					!visited.count(new_word)) {
					result.insert(new_word);
				}
				swap(c, new_word[i]);
			}
		}

		return result;
	};

	current.insert(start);
	while (!current.empty() && !found) {
		for (const auto& word : current)
			visited.insert(word);
		for (const auto& word : current) {
			const auto new_states = state_extend(word);
			for (const auto &state : new_states) {
				if (state_is_target(state)) found = true;
				next.insert(state);
				father[state].push_back(word);
			}
		}

		current.clear();
		swap(current, next);
	}
	vector<vector<string> > result;
	if (found) {
		vector<string> path;
		gen_path(father, path, start, end, result);
	}
	return result;

}

int main()
{
	unordered_set<string> dict = { "hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot" };
	vector<vector<string>> ret = findLadders("hot", "dog", dict);
	return 0;
}
