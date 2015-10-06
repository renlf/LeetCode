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
