#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	unordered_map<char, int> dict;
	unordered_map<int, int> record;
	vector<string> ret;
	if (s.length() < 10)
		return ret;
	int key = 0;

	dict['A'] = 0;
	dict['C'] = 1;
	dict['G'] = 2;
	dict['T'] = 3;

	for (int i = 0; i < 10; i++)
	{
		key = (key << 2) | (dict[s[i]]);
	}
	record[key] = 1;

	for (int i = 10; i < s.size(); i++)
	{
		key = 0xFFFFF & ((key << 2) | (dict[s[i]]));
		if (record.find(key) == record.end())
		{
			record[key] = 1;
		}
		else
		{
			if (record[key] == 1)
			{
				ret.push_back(s.substr(i-9, 10));
				record[key]++;
			}
		}
	}
	return ret;
}
