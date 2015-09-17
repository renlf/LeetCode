#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bt_BST(vector<int>& nums, int start, int end)
{
	if (start > end)
		return NULL;
	if (start == end)
		return (new TreeNode(nums[start]));
	int mid = (start + end) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = bt_BST(nums, start, mid - 1);
	root->right = bt_BST(nums, mid + 1, end);
	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return bt_BST(nums, 0, nums.size() - 1);
}
