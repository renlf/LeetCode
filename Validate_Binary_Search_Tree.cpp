#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool bt_isValid(TreeNode* root, long long min_val, long long max_val)
{
	if (root == NULL)
		return true;
	if (root->val > min_val && root->val < max_val)
	{
		bool ret = true;
		if (root->left != NULL)
			ret = bt_isValid(root->left, min_val, root->val);
		if (root->right != NULL)
			ret = ret && bt_isValid(root->right, root->val, max_val);
		return ret;
	}
	else
		return false;
}

bool isValidBST(TreeNode* root) {
	return bt_isValid(root, LLONG_MIN, LLONG_MAX);
}
