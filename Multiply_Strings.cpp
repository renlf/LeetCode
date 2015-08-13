#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
		return "0";

	vector<int> ret;
	ret.resize(num1.length() + num2.length(), 0);
	int carry = 0;
	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int val1 = num1[i] - '0';
		int j;
		carry = 0;
		int index = 0;
		for (j = num2.length() - 1; j >= 0; j--)
		{
			int val2 = num2[j] - '0';
			index = (num1.size() - i - 1) + (num2.size() - j -1);
			val2 *= val1;
			ret[index] = ret[index] + val2 % 10 + carry;
			
			carry = val2 / 10 + ret[index] / 10;
			ret[index] %= 10;
		}
		ret[index + 1] += carry;
	}

	string result = "";
	if (ret[ret.size() - 1] != 0)
		result.push_back('0' + ret[ret.size() - 1]);
	for (int i = ret.size() - 2; i >= 0; i--)
	{
		result.push_back('0' + ret[i]);
	}
	return result;
}

int main()
{
	string num1 = "98";
	string num2 = "9";
	string result = multiply(num1, num2);
	return 0;
}
