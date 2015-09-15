#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void bt_traversal(TreeNode* root, vector<int> &ret)
{
	if (root == NULL)
		return;
	if (root->left != NULL)
		bt_traversal(root->left, ret);
	ret.push_back(root->val);
	if (root->right != NULL)
		bt_traversal(root->right, ret);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ret;
	bt_traversal(root, ret);
	return ret;
}
