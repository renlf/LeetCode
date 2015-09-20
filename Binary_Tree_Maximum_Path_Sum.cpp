#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int bt_maxPathSum(TreeNode* root, vector<int> &data)
{
	if (root == NULL)
		return 0;
	int l_max = bt_maxPathSum(root->left, data);
	int r_max = bt_maxPathSum(root->right, data);

	data.push_back(max(l_max, 0) + max(r_max, 0) + root->val);
	return max(max(l_max, r_max), 0) + (root->val);
}

int maxPathSum(TreeNode* root) {
	vector<int> data;
	int maxp = bt_maxPathSum(root, data);
	for (int i = 0; i < data.size(); i++)
	{
		maxp = max(maxp, data[i]);
	}
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
