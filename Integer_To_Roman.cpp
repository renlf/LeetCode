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

string intToRoman2(int num)
{
	string numerals = "IVXLCDM";
	string result = "";

	int devided = 1000;
	int index = 6;
	while (num)
	{
		int dev_result = num / devided;
		if(dev_result <= 3)
        {
            result.append(dev_result, numerals[index]);
        }
        else if (dev_result == 4)
        {
            result.append(1, numerals[index]);
            result.append(1, numerals[index + 1]);
        }
        else if (dev_result <= 8)
        {
            result.append(1, numerals[index + 1]);
            result.append((dev_result - 5), numerals[index]);
        }
        else
        {
            result.append(1, numerals[index]);
            result.append(1, numerals[index + 2]);
        }
		num = num % devided;
		devided /= 10;

        index -= 2;
	}
	return result;
}

int main()
{
	string result = intToRoman(4);
	cout << result << endl;
	return 0;
}
