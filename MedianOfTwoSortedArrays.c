#define min(x,y) (((x) < (y)) ? (x) : (y))

double FindKth(int a[], int a_size, int b[], int b_size, int k)
{
	if (a_size == 0)
		return b[k - 1];
	if (b_size == 0)
		return a[k - 1];
	if (k <= 1)
		return min(a[0], b[0]);

	int a_midlen = a_size / 2;
	int b_midlen = b_size / 2;

	if (a[a_midlen] <= b[b_midlen])
	{
		if ((a_midlen + b_midlen + 1) >= k)
			return FindKth(a, a_size, b, b_midlen, k);
		else
			return FindKth((a + a_midlen + 1), (a_size - a_midlen - 1), b, b_size, (k - a_midlen - 1));
	}
	else
	{
		if ((a_midlen + b_midlen + 1) >= k)
			return FindKth(a, a_midlen, b, b_size, k);
		else
			return FindKth(a, a_size, (b + b_midlen + 1), (b_size - b_midlen - 1), (k - b_midlen - 1));
	}
}

double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int total_size = nums1Size + nums2Size;
	int mid_pos = total_size / 2;
	if (total_size % 2 == 1)
		return FindKth(nums1, nums1Size, nums2, nums2Size, mid_pos + 1);
	else
		return (double)(FindKth(nums1, nums1Size, nums2, nums2Size, mid_pos) + FindKth(nums1, nums1Size, nums2, nums2Size, mid_pos + 1)) / 2.0;
}