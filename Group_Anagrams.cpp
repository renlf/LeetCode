#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector< vector<string> > ret;
	unordered_map<string, vector<string>> hm_strs;
	for (int i = 0; i < strs.size(); i++)
	{
		string key = strs[i];
		sort(key.begin(), key.end());
		hm_strs[key].push_back(strs[i]);
	}
	unordered_map<string, vector<string>>::iterator iter;
	for (iter = hm_strs.begin(); iter != hm_strs.end(); iter++)
	{
		sort((iter->second).begin(), (iter->second).end());
		ret.push_back(iter->second);
	}
	return ret;
}

int main()
{
	vector<string> data = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ret = groupAnagrams(data);
	return 0;
}
