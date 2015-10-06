#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ret;
	if (root == NULL)
		return ret;

	stack<TreeNode*> st;
	TreeNode* cur = root;
	TreeNode* pre = NULL;

	do
	{
		while (cur)
		{
			st.push(cur);
			cur = cur->left;
		}
		pre = NULL;
		while (!st.empty())
		{
			cur = st.top();

			if (cur->right == pre)
			{
				st.pop();
				ret.push_back(cur->val);
				pre = cur;
			}
			else
			{
				cur = cur->right;
				break;
			}
		}
	} while (!st.empty());

	return ret;
}
