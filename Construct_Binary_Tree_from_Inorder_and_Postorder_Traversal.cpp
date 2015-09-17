#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bt_buildTree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe)
		return NULL;
	TreeNode * root = new TreeNode(postorder[pe]);
	int l_end;
	for (l_end = is; l_end <= ie; l_end++)
	{
		if (inorder[l_end] == postorder[pe])
			break;
	}
	int l_num = l_end - is;

	root->left = bt_buildTree(inorder, postorder, is, l_end - 1, ps, ps + l_num - 1);
	root->right = bt_buildTree(inorder, postorder, l_end + 1, ie, ps + l_num, pe - 1);
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.size() == 0)
		return NULL;
	return bt_buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main()
{
	vector<int> inorder = { 2, 1 };
	vector<int> postorder = { 2, 1 };
	TreeNode* ret = buildTree(inorder, postorder);
	return 0;
}
