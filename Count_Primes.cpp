#include <vector>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<int> prime(n, true);

		for (int i = 2; i * i < n; i++)
		{
			for (int j = i * i; j < n; j += i)
			{
				prime[j] = false;
			}
		}
		int count = 0;
		for (int i = 2; i < n; i++)
		{
			if (prime[i] == true)
				count++;
		}
		return count;
	}
};
