#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
	unordered_map<char, int> t_store;
	for (int i = 0; i < t.length(); i++)
	{
		if (t_store[t[i]])
			t_store[t[i]]++;
		else
			t_store[t[i]] = 1;
	}
	int former = 0;
	string ret = "";
	vector<int> index;
	unordered_map<char, int> t_cpy = t_store;
	unordered_map<char, int> t_remove = t_store;
	unordered_map<char, int> t_record;
	while (former < s.length())
	{
		while (former < s.length() && !t_cpy[s[former]])
			former++;
		if (former >= s.length())
			break;		
		while (former < s.length() && !t_remove.empty())
		{
			if (t_cpy[s[former]])
			{				
				t_cpy[s[former]]--;
				if (t_cpy[s[former]] == 0)
				{
					t_remove.erase(s[former]);
				}
			}
			if (t_store[s[former]] >= 1)
				index.push_back(former);
			t_record[s[former]]++;
			former++;
		}
		if (!t_remove.empty())
			break;
		t_cpy = t_store;
		int i;
		for (i = 0; i < index.size(); i++)
		{
			int j = index[i];
			if (t_cpy[s[j]] >= 1)
			{
				if (t_cpy[s[j]] == t_record[s[j]])
				{
					t_remove[s[j]] = 1;
					t_record[s[j]] = t_store[s[j]] - 1;
					t_cpy[s[j]] = 1;
					break;
				}
				else
				{
					t_record[s[j]]--;
				}
			}
		}
		string tmp = s.substr(index[i], former - index[i]);
		if (ret.length() == 0 || tmp.length() < ret.length())
			ret = tmp;
		former = index[index.size() - 1] + 1;
		index.erase(index.begin(), index.begin() + i + 1);
	}
	return ret;
}

int main()
{
	string S = "ADOBECODEBANC";
	string T = "ABC";
	string ret = minWindow(S, T);
	return 0;
}
