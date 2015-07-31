#include <string>
#include <vector>

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

vector<int> KMPProcessing(string needle)
{
	vector<int> result;
	result.resize(needle.length(), -1);

	int j = -1;
	for (int i = 1; i < needle.length(); i++)
	{
		while (j!= -1 && needle[j + 1] != needle[i])
			j = result[i];
		if (needle[j + 1] == needle[i])
			j++;
		result[i] = j;
	}

	return result;
}

int strStr2(string haystack, string needle) {
	if (haystack == needle || needle.length() == 0)
		return 0;
	
	int h_len = haystack.length();
	int n_len = needle.length();
	
	if (h_len == 0 || h_len < n_len)
		return -1;

	vector<int> match = KMPProcessing(needle);
	int j = -1;
	for (int i = 0; i < h_len; i++)
	{
		while (j != -1 && haystack[i] != needle[j + 1])
		{
			j = match[j];
		}
		if (haystack[i] == needle[j + 1])
		{
			j++;
		}
		if (j + 1 == n_len)
			return i - j;
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
