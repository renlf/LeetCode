#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bt_buildTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie)
{
	if (ps > pe || is > ie)
		return NULL;
	TreeNode* root = new TreeNode(preorder[ps]);
	int l_end;
	int r_start;
	for (l_end = is; l_end <= ie; l_end++)
	{
		if (inorder[l_end] == preorder[ps])
			break;
	}
	int l_num = l_end - is;
	r_start = l_end + 1;

	root->left = bt_buildTree(preorder, inorder, ps + 1, ps + l_num, is, l_end - 1);
	root->right = bt_buildTree(preorder, inorder, ps + 1 + l_num, pe, r_start, ie);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0)
		return NULL;
	return bt_buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main()
{
	vector<int> preorder = { 1, 2, 3 };
	vector<int> inorder = { 2, 3, 1 };
	TreeNode* ret = buildTree(preorder, inorder);
	return 0;
}
