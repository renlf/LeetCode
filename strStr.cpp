#include <string>

using namespace std;

int strStr(string haystack, string needle) {
	if (haystack == needle)
		return 0;
	int h_len = haystack.length();
	int n_len = needle.length();
	if (h_len == 0 || h_len < n_len)
		return -1;
	int remain = h_len - n_len;
	for (int i = 0; i <= remain; i++)
	{
		if (haystack.substr(i, needle.size()) == needle)
			return i;
	}
	return -1;
}

int main()
{
	string haystack = "mississippi";
	string needle = "pi";
	int result = strStr(haystack, needle);
	return 0;
}
