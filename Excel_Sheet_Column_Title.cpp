#include <string>

using namespace std;

string convertToTitle(int n) {
	string ret = "";
	while (n)
	{
		int remain = n % 26;
		n = n / 26;
		if (remain == 0)
		{
			ret.push_back('Z');
			n--;
		}
		else
		{
			ret.push_back('A' + remain - 1);
		}		
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
