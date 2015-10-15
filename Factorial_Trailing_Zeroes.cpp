#include <algorithm>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int count = 0;
		long long divide = 5;
		while (n >= divide)
		{
			count += n / divide;
			divide *= 5;
		}
		return count;
	}
};
