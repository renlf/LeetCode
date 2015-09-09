#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& height) {
	int max_area = 0;
	stack<int> st;
	height.insert(height.begin(), -1);
	height.push_back(0);
	for (int i = 0; i < height.size(); i++)
	{
		while (!st.empty() && height[i] < height[st.top()])
		{
			int h = height[st.top()];
			st.pop();
			int tmp_area = h * (i - st.top() - 1);
			max_area = max(max_area, tmp_area);
		}
		st.push(i);
	}
	return max_area;
}
