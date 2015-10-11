#include <sstream>

using namespace std;

int compareVersion(string version1, string version2) {
	istringstream v1(version1 + ".");
	istringstream v2(version2 + ".");
	int num1 = 0;
	int num2 = 0;
	char dot;
	while (v1.good() || v2.good())
	{
		if (v1.good())
			v1 >> num1 >> dot;
		if (v2.good())
			v2 >> num2 >> dot;
		if (num1 > num2)
			return 1;
		if (num1 < num2)
			return -1;
		num1 = 0;
		num2 = 0;
	}
	return 0;
}
