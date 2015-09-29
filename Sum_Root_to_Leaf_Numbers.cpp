#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void bt_sum(TreeNode* root, int path, int &sum)
{
	if (root == NULL)
		return;
	path = 10*path + root->val;
	if (root->left == NULL && root->right == NULL)
		sum += path;
	if (root->left != NULL)
		bt_sum(root->left, path, sum);
	if (root->right != NULL)
		bt_sum(root->right, path, sum);
}

int sumNumbers(TreeNode* root) {
	if (root == NULL)
		return 0;
	int path = 0;
	int sum = 0;
	bt_sum(root, path, sum);
	return sum;
}
