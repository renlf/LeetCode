#include <vector>

using namespace std;

void bt_combine(vector<vector<int>> &ret, vector<int> sub_ret, int n, int k)
{
	if (k == 0)
	{
		ret.push_back(sub_ret);
		return;
	}
	int sub_size = sub_ret.size();
	int i = 1;
	if (sub_size > 0)
		i = sub_ret[sub_size - 1] + 1;
	for (; i <= n - k + 1; i++)
	{
		sub_ret.push_back(i);
		bt_combine(ret, sub_ret, n, k - 1);
		sub_ret.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ret;
	vector<int> sub_ret;
	bt_combine(ret, sub_ret, n, k);
	return ret;
}

int main()
{
	vector<vector<int>> ret = combine(4, 2);
	return 0;
}
