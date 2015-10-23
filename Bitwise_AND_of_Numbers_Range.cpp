class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int sub = m ^ n;
		int count = 0;
		while (sub)
		{
			sub = sub >> 1;
			count++;
		}
		return (n >> count) << count;
	}
};
