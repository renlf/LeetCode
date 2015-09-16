#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ret;
	if (root == NULL)
		return ret;
	queue<TreeNode* > que;
	que.push(root);
	while (!que.empty())
	{
		vector<int> sub_ret;
		int count = que.size();
		while (count--)
		{
			TreeNode* tt = que.front();
			sub_ret.push_back(tt->val);
			if (tt->left != NULL)
				que.push(tt->left);
			if (tt->right != NULL)
				que.push(tt->right);
			que.pop();
		}
		if (sub_ret.size() > 0)
			ret.push_back(sub_ret);
	}
	return ret;
}
