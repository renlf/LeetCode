#include <iostream>
#include <string>

using namespace std;

bool isMatch(const char * s, const char * p)
{
    if(*p == '\0')
        return (*s == '\0');
    if(*(p+1) == '*')
    {
		while (*s == *p || (*p == '.' && *s != '\0'))
		{
			if (isMatch(s++, p + 2))
				return true;
		}
        return isMatch(s, p+2);
    }
    else
    {
		if (*s == *p || (*p == '.' && *s != '\0'))
			return isMatch(s + 1, p + 1);
		else
			return false;
    }
}

int main()
{
	string str = "aaa";
	string parten = "a.*a*c*a";
	cout << str << " " << parten << endl;
	bool result;
	result = isMatch(str.c_str(), parten.c_str());
	cout << result << endl;
	return 0;
}
