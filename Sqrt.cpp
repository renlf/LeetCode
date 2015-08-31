int mySqrt(int x) {
	long long left = 0;
	long long right = x;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (mid * mid == x)
			return mid;
		else if (mid * mid < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}

int main()
{
	int ret = mySqrt(2147395599);
	return 0;
}
