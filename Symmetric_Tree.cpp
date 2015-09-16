#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool bt_isSymmetric(TreeNode* lc, TreeNode * rc)
{
	if (lc == NULL && rc == NULL)
		return true;
	else if (lc == NULL || rc == NULL)
		return false;
	if (lc->val == rc->val)
	{
		return (bt_isSymmetric(lc->left, rc->right) && bt_isSymmetric(lc->right, rc->left));
	}
	else
		return false;
}

bool isSymmetric(TreeNode* root) {
	if (root == NULL)
		return true;
	return bt_isSymmetric(root->left, root->right);
}
