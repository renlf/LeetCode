#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void bt_levelOrder(vector<vector<int>> &ret, queue<TreeNode*> que)
{
	if (que.empty())
		return;
	vector<int> sub_ret;
	int count = que.size();
	for (int i = 0; i < count; i++)
	{
		TreeNode* tt = que.front();
		sub_ret.push_back(tt->val);
		if (tt->left != NULL)
			que.push(tt->left);
		if (tt->right != NULL)
			que.push(tt->right);
		que.pop();
	}
	bt_levelOrder(ret, que);
	if (sub_ret.size() > 0)
		ret.push_back(sub_ret);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> ret;
	if (root == NULL)
		return ret;
	queue<TreeNode*> que;
	que.push(root);
	bt_levelOrder(ret, que);
	return ret;
}
