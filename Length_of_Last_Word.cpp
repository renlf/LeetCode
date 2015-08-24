#include <string>

using namespace std;

int lengthOfLastWord(string s) {
	if (s.size() == 0)
		return 0;
	int len = 0;
	int index = s.size() - 1;
	while (index >= 0 && s[index] == ' ')
	{
		index--;
	}
	while (index >= 0 && s[index] != ' ')
	{
		index--;
		len++;
	}
	return len;
}

int main()
{
	string s = "a ";
	int ret = lengthOfLastWord(s);
	return 0;
}
