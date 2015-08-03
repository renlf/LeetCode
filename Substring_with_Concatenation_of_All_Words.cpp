#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> result;
	if (s.size() == 0 || words.size() == 0)
		return result;

	if (s.size() < (words.size() * words[0].size()))
		return result;

	int words_size = words.size();
	int word_len = words[0].size();
	map<string, int> words_count;
	map<string, int> words_comp;

	for (int i = 0; i < words_size; i++)
	{
		words_comp[words[i]]++;
	}
	int matched_count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		matched_count = 0;
		string tmp = s.substr(i, word_len);
		if (words_comp.find(tmp) == words_comp.end())
		{
			continue;
		}
		words_count[tmp]++;
		matched_count++;

		for (int j = i + word_len; j < s.size(); j += word_len)
		{
			string next_word = s.substr(j, word_len);
			if (words_comp.find(next_word) == words_comp.end())
			{
				break;
			}
			if (words_count[next_word] == words_comp[next_word])
			{
				break;
			}

			words_count[next_word]++;
			matched_count++;
			if (matched_count == words_size)
			{
				break;
			}
		}
		if (matched_count == words_size)
		{
			result.push_back(i);
		}
		words_count.clear();
	}
	return result;
}

vector<int> findSubstring2(string s, vector<string>& words) {
	vector<int> result;
	if (s.size() == 0 || words.size() == 0)
		return result;

	if (s.size() < (words.size() * words[0].size()))
		return result;

	int words_size = words.size();
	int word_len = words[0].size();
	int word_total = words_size * word_len;
	map<string, int> words_count;
	map<string, int> words_comp;
	
	for (int i = 0; i < words_size; i++)
	{
		words_comp[words[i]]++;
	}

	for (int i = 0; i + word_total <= s.size(); i++)
	{
		words_count.clear();
		bool matched = true;
		for (int j = 0; j < words_size; j++)
		{
			string tmp = s.substr(i + j * word_len, word_len);
			if (words_comp[tmp] > words_count[tmp])
			{
				words_count[tmp]++;
			}
			else
			{
				matched = false;
				break;
			}
		}
		if (matched)
			result.push_back(i);
	}

	return result;
}

int main()
{
	string s = "a";
	vector<string> words = {"a"};
	vector<int> result = findSubstring(s, words);
	return 0;
}
