#include <string>

using namespace std;

void reverseWords(string &s) {
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i++)
	{
		int j;
		if (s[i] == ' ')
		{
			j = s.find_first_not_of(' ', i);
			s.erase(i, j - i);
		}
		j = s.find_first_of(' ', i);
		j = (j == string::npos) ? s.size() : j;
		reverse(s.begin() + i, s.begin() + j);
		i = j;
	}
	if (*(s.end() - 1) == ' ')
		s.erase(s.end() - 1);
}
