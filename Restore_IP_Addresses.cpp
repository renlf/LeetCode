#include <vector>
#include <string>

using namespace std;

void bt_restoreIP(vector<string> &ret, string sub_ret, string ip, int index, int count)
{
	if (count > 4 || index >= ip.size())
	{
		if (index == ip.size() && count == 4)
			ret.push_back(sub_ret);
		return;
	}
	int remain_str = ip.length() - index;
	int remain_count = 4 - count;
	if (remain_str < remain_count || remain_str > 3 * remain_count)
		return;
	for (int i = 1; i <= 3; i++)
	{
		string tmp = ip.substr(index, i);
		int val = stoi(tmp);
		if (val > 255)
			break;
		string new_sub = sub_ret + tmp;
		if (count < 3)
			new_sub += ".";
		bt_restoreIP(ret, new_sub, ip, index + i, count + 1);
		if (val == 0)
			break;
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> ret;
	if (s.length() < 4)
		return ret;
	string sub_ret = "";
	bt_restoreIP(ret, sub_ret, s, 0, 0);
	return ret;
}

int main()
{
	vector<string> ret = restoreIpAddresses("25525511135");
	return 0;
}
