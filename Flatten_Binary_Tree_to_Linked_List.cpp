#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;
	stack<TreeNode*> st;
	st.push(root);
	TreeNode* pre = root;
	while (!st.empty())
	{
		TreeNode* tt = st.top();
		st.pop();
		if (tt->right != NULL)
			st.push(tt->right);
		if (tt->left != NULL)
			st.push(tt->left);
		if (tt != root)
		{
			pre->right = tt;
			pre->left = NULL;
			pre = tt;
		}
	}
	pre->right = NULL;
	pre->left = NULL;
}
