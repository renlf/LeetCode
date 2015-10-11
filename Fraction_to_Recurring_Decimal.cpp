#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
	if (numerator == 0)
		return "0";
	string ret = "";
	if ((numerator < 0) ^ (denominator < 0))
		ret += "-";

	long long numer = (numerator < 0) ? ((long long)numerator * -1) : numerator;
	long long demom = (denominator < 0) ? ((long long)denominator * -1) : denominator;

	long long tmp = numer / demom;
	string str;
	stringstream strstream;
	strstream << tmp;
	strstream >> str;
	ret += str;

	long long remain = (numer % demom) * 10;
	if (remain != 0)
	{
		ret += ".";
	}

	unordered_map<long long, int> record;
	int index = ret.length();
	while (remain)
	{
		long long num = remain / demom;
		if (record.find(remain) != record.end())
		{
			ret.insert(ret.begin() + record[remain], '(');
			ret.push_back(')');
			break;
		}
		else
		{
			record[remain] = index;
			ret += to_string(num);
		}
		remain = (remain % demom) * 10;
		index++;
	}
	return ret;
}

int main()
{
	string ret = fractionToDecimal(-1, INT_MIN);
	return 0;
}
