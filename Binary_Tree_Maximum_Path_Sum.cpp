#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int bt_maxPathSum(TreeNode* root, int &maxp)
{
	if (root == NULL)
		return 0;
	int l_max = bt_maxPathSum(root->left, maxp);
	int r_max = bt_maxPathSum(root->right, maxp);

	maxp = max(maxp, (max(l_max, 0) + max(r_max, 0) + root->val));
	int ret = max(max(l_max, r_max), 0) + (root->val);
	maxp = max(maxp, ret);
	return ret;
}

int maxPathSum(TreeNode* root) {
	int maxp = INT_MIN;
	bt_maxPathSum(root, maxp);
	return maxp;
}

int main()
{
	TreeNode *root = new TreeNode(-2);
	TreeNode* ch = new TreeNode(1);
	root->left = ch;
	int ret = maxPathSum(root);
	return 0;
}
