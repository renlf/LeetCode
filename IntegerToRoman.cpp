#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num) {
	int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string numerals[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	string result = "";

	for (int i = 0; i < 13 && num > 0; i++)
	{
		while (num - values[i] >= 0)
		{
			result.append(numerals[i]);
			num -= values[i];
		}
	}

	return result;
}

int main()
{
	string result = intToRoman(4);
	cout << result << endl;
	return 0;
}
