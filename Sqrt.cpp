int mySqrt(int x) {
	long long left = 0;
	long long right = x;
	while (left <= right)
	{
		long long mid = left / 2 + right / 2;
		if (left % 2 == 1 && right % 2 == 1)
			mid++;
		if (mid * mid == x)
			return mid;
		else if (mid * mid < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	int ret = left / 2 + right / 2;
	if (left % 2 == 1 && right % 2 == 1)
		ret++;
	return ret;
}

int main()
{
	int ret = mySqrt(2147395599);
	return 0;
}
