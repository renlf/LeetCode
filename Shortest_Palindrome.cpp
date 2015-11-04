#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		string rev = s;
		reverse(rev.begin(), rev.end());
		rev = s + "@" + rev;
		int len = rev.length();
		vector<int> next(len);
		next[0] = -1;
		int j = -1;
		for (int i = 1; i < len; i++)
		{
			while (j > -1 && rev[j + 1] != rev[i])
				j = next[j];
			if (rev[i] == rev[j + 1])
				j++;
			next[i] = j;
		}
		j = next[len - 1];
		return rev.substr(s.length() + 1, s.length() - j - 1) + s;
	}
};
