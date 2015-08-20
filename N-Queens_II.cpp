
int max_index = 0;

void Queens(int &count, int raw, int left, int right)
{
	if (raw == max_index)
	{
		count++;
		return;
	}
	int index = max_index & (~(raw | left | right));
	while (index > 0)
	{
		int next = index & (-index);
		Queens(count, raw + next, (left + next) << 1, (right + next) >> 1);
		index -= next;
	}
}

int totalNQueens(int n) {
	max_index = (1 << n) - 1;
	int ret = 0;
	Queens(ret, 0, 0, 0);
	return ret;
}

int main()
{
	int result = totalNQueens(4);
	return 0;
}
