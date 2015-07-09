#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	if (strs.size() == 1)
		return strs[0];
	string com_prex = "";
	for (int i = 0; i < strs[0].size(); i++)
	{
		int j = 0;
		int k = 1;
		while (k < strs.size())
		{
			if (strs[j][i] != strs[k][i])
			{
				break;
			}
			k++;
		}
		if (k != strs.size())
		{
			break;
		}
		com_prex.append(1,strs[j][i]);
	}
	return com_prex;
}
