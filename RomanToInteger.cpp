#include <iostream>
#include <string>

using namespace std;

int romanToInt(string s)
{
	int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string numerals[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int result = 0;
	bool two_match = false;
	int str_len = s.length();
	for (int i = 0; i < str_len;)
	{
		two_match = false;
		if (i + 1 < str_len)
		{
			string str_sub = s.substr(i, 2);
			for (int j = 0; j < 13; j++)
			{
				if (str_sub == numerals[j])
				{
					result += values[j];
					two_match = true;
					i += 2;
					break;
				}
			}
		}
		if (two_match == false)
		{
			string str_sub = s.substr(i, 1);
			for (int j = 0; j < 13; j++)
			{
				if (str_sub == numerals[j])
				{
					result += values[j];
					i++;
					break;
				}
			}
		}
	}
	return result;
}

int romanToInteger2(string s)
{
	int values[7] = { 1000, 500,  100, 50, 10, 5, 1 };
	string numerals[7] = { "M", "D", "C", "L", "X", "V", "I" };
	int former = 0;
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		string sub_str = s.substr(i, 1);
		int current_val = 0;
		for (int j = 0; j < 7; j++)
		{
			if (sub_str == numerals[j])
			{
				current_val = values[j];
				result += values[j];
				break;
			}
		}
		if (current_val > former)
		{
			result = result - 2 * former;
		}
		former = current_val;
	}
	return result;
}

int main()
{
	string str = "MDCCCLXXXIV";
	cout << str.substr(9, 2) << endl;
	int result = romanToInt(str);
	cout << result << endl;
	return 0;
}
