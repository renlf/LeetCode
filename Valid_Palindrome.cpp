#include <string>

using namespace std;

bool isPalindrome(string s) {
	if (s.length() <= 1)
		return true;
	int left = 0;
	int right = s.length() - 1;
	while (left < right)
	{
		while (left < right && !((s[left] >= 'A' && s[left] <= 'Z')
			|| (s[left] >= 'a' && s[left] <= 'z')
			|| (s[left] - '0' >= 0 && s[left] - '0' <= 9)))
			left++;
		while (left < right && !((s[right] >= 'A' && s[right] <= 'Z')
			|| (s[right] >= 'a' && s[right] <= 'z')
			|| (s[right] - '0' >= 0 && s[right] - '0' <= 9)))
			right--;
		if (left < right && s[left] != s[right] && abs(s[left] - s[right]) != 32)
			return false;
		left++;
		right--;
	}
	return true;
}

int main()
{
	bool ret = isPalindrome("aA");
	return 0;
}
