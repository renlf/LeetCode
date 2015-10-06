#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ret;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* cur = st.top();
		st.pop();
		if (cur != NULL)
		{
			ret.push_back(cur->val);
			st.push(cur->right);
			st.push(cur->left);
		}
	}
	return ret;
}

//Morris Traveral
vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> ret;
	TreeNode* cur = root;
	TreeNode * pre = NULL;
	while (cur)
	{
		if (cur->left == NULL)
		{
			ret.push_back(cur->val);
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while (pre->right != NULL && pre->right != cur)
				pre = pre->right;
			if (pre->right == NULL)
			{
				ret.push_back(cur->val);
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
	return ret;
}
