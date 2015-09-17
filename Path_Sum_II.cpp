#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void bt_pathSum(vector<vector<int>> &ret, vector<int> sub_ret, TreeNode* root, int sum)
{
	if (root == NULL)
		return;
	sub_ret.push_back(root->val);
	if (root->left == NULL && root->right == NULL)
	{
		if (sum == root->val)
		{
			ret.push_back(sub_ret);
		}
		return;
	}
	if (root->left != NULL)
	{
		bt_pathSum(ret, sub_ret, root->left, sum - root->val);
	}
	if (root->right != NULL)
	{
		bt_pathSum(ret, sub_ret, root->right, sum - root->val);
	}
	sub_ret.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> ret;
	vector<int> sub_ret;
	bt_pathSum(ret, sub_ret, root, sum);
	return ret;
}
