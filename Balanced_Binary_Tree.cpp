#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool bt_isBalanced(TreeNode* root, int & depth)
{
	if (root == NULL)
	{
		depth = 0;
		return true;
	}
	int l_depth;
	int r_depth;
	if (bt_isBalanced(root->left, l_depth) && bt_isBalanced(root->right, r_depth))
	{
		if (abs(l_depth - r_depth) > 1)
			return false;
		depth = max(l_depth, r_depth) + 1;
		return true;
	}
	else
		return false;
}

bool isBalanced(TreeNode* root) {
	int depth;
	return bt_isBalanced(root, depth);
}
