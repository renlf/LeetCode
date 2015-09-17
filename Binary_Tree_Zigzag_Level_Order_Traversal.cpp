#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> ret;
	if (root == NULL)
		return ret;
	stack<TreeNode*> st;
	st.push(root);
	int judge = 0;
	while (!st.empty())
	{
		vector<int> sub_ret;
		stack<TreeNode*> new_st;
		while (!st.empty())
		{
			TreeNode* tmp = st.top();
			sub_ret.push_back(tmp->val);
			if (judge % 2 == 1)
			{
				if (tmp->right != NULL)
					new_st.push(tmp->right);
				if (tmp->left != NULL)
					new_st.push(tmp->left);
			}
			else
			{
				if (tmp->left != NULL)
					new_st.push(tmp->left);
				if (tmp->right != NULL)
					new_st.push(tmp->right);
			}
			st.pop();
		}
		ret.push_back(sub_ret);
		st = new_st;
		judge++;
	}
	return ret;
}
