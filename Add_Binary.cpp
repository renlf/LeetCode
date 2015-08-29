#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
	int flag = 0;
	string ret = "";
	int a_len = a.length();
	int b_len = b.length();
	int max_len = max(a_len, b_len);
	for (int i = 0; i < max_len; i++)
	{
		int a_num = 0;
		int b_num = 0;
		if(i < a_len)
			a_num = a[a_len - i - 1] - '0';
		if (i < b_len)
			b_num = b[b_len - i - 1] - '0';
		int tmp = a_num + b_num + flag;
		if (tmp >= 2)
			flag = 1;
		else
			flag = 0;
		ret.insert(ret.begin(), tmp % 2 + '0');
	}
	if (flag)
		ret.insert(ret.begin(), '1');
	return ret;
}

int main()
{
	string a = "100";
	string b = "110010";
	string ret = addBinary(a, b);
	return 0;
}
