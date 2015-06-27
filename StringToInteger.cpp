#include <string>
#include <limits>

using namespace std;

int myAtoi(string str)
{
	if (str.length() == 0)
		return 0;
	int index = 0;
	int op = 1;
	int result = 0;
	while (str[index] == ' ')
	{
		index++;
	}
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '+')
			op = 1;
		else
			op = -1;
		index++;
	}
	for (int i = index; i < str.length(); i++)
	{
		int single = str[i] - '0';
		if (single < 0 || single > 9)
		{
			return result;
		}
		int tmp = result;
		for (int j = 0; j < 9; j++)
		{
			if (op == 1 && result > 0 && result > numeric_limits<int>::max() - tmp)
				return numeric_limits<int>::max();
			if (op == -1 && (-1 * result) < 0 && (-1 * result) < numeric_limits<int>::min() + tmp)
				return numeric_limits<int>::min();
			result += tmp;
		}
		if (op == 1 && result > 0 && result > numeric_limits<int>::max() - single)
			return numeric_limits<int>::max();
		if (op == -1 && result > 0 && (-1 * result) < numeric_limits<int>::min() + single)
			return numeric_limits<int>::min();
		result += single;
	}
	return result * op;
}
int main()
{
	string num = "  -0012a42";
	int result = myAtoi(num);
	return 0;
}
