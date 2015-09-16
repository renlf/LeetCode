#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> bt_generate(int left, int right)
{
	vector<TreeNode*> ret;
	if (left > right)
	{
		ret.push_back(NULL);
		return ret;
	}
	for (int i = left; i <= right; i++)
	{
		vector<TreeNode*> lst = bt_generate(left, i - 1);
		vector<TreeNode*> rst = bt_generate(i + 1, right);
		for (int j = 0; j < lst.size(); j++)
		{
			for (int k = 0; k < rst.size(); k++)
			{
				TreeNode* root = new TreeNode(i);
				root->left = lst[j];
				root->right = rst[k];
				ret.push_back(root);
			}
		}
	}
	return ret;
}

vector<TreeNode*> generateTrees(int n) {
      return bt_generate(1, n); 
}
