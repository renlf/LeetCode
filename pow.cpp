double myPow(double x, int n) {
	if (n == 0)
		return 1.0;
	if (n == 1)
		return x;
	if (n == -1)
		return 1.0 / x;

	int bn = n / 2;
	int remain = n - 2 * bn;
	double bn_ret = myPow(x, bn);
	double rem_ret = myPow(x, remain);
	return bn_ret * bn_ret * rem_ret;
}

int main()
{
	double result = myPow(34.00515, -3);
	return 0;
}
