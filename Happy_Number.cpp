#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> loop;
		loop.insert(n);
		while (n)
		{
			int n_val = 0;
			int record = n;
			while (n)
			{
				n_val += (n % 10) * (n % 10);
				n /= 10;
			}
			if (n_val == 1)
				return true;
			if (loop.find(n_val) != loop.end())
				return false;
			n = n_val;
			loop.insert(n_val);
		}
		return false;
	}
};
