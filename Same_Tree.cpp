#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	else if (p == NULL || q == NULL)
		return false;
	if (p->val == q->val)
	{
		bool l_cmp = isSameTree(p->left, q->left);
		bool r_cmp = isSameTree(p->right, q->right);
		return (l_cmp && r_cmp);
	}
	else
		return false;
}
