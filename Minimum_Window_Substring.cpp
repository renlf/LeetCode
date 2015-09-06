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

string minWindow2(string s, string t) {
	int t_store[256];
	int t_record[256];
	memset(t_store, 0, sizeof(t_store));
	memset(t_record, 0, sizeof(t_record));
	int s_len = s.length();
	int t_len = t.length();

	if (s_len == 0 || t_len == 0 || s_len < t_len)
		return "";
	for (int i = 0; i < t_len; i++)
	{
		t_store[t[i]]++;
	}
	int former = 0;
	int backer = 0;
	int match_count = 0;
	int pos = 0;
	int min_len = s_len + 1;
	while (former < s_len)
	{
		while (former < s_len && match_count < t_len)
		{
			t_record[s[former]]++;
			if (t_record[s[former]] <= t_store[s[former]])
			{
				match_count++;
			}
			former++;
		}
		while (backer < former && t_record[s[backer]] > t_store[s[backer]])
		{
			t_record[s[backer]]--;
			backer++;
		}
		if (match_count == t_len)
		{
			if (min_len > former - backer)
			{
				pos = backer;
				min_len = former - backer;
			}
		}
		t_record[s[backer]]--;
		match_count--;
		backer++;
	}
	if (min_len == s_len + 1)
		return "";
	else
		return s.substr(pos, min_len);
}

int main()
{
	string S = "ADOBECODEBANC";
	string T = "ABC";
	string ret = minWindow(S, T);
	return 0;
}
