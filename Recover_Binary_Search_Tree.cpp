#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode* root) {
	TreeNode* cur = root;
	TreeNode* parent = NULL;
	TreeNode* sw_one = NULL;
	TreeNode* sw_two = NULL;
	bool flag = false;
	while (cur != NULL)
	{
		if (cur->left == NULL)
		{
			if (parent && parent->val > cur->val)
			{
				if (!flag)
					sw_one = parent;
				sw_two = cur;
				flag = true;
			}
			parent = cur;
			cur = cur->right;
		}
		else
		{
			TreeNode* iter = cur->left;
			while (iter->right != NULL && iter->right != cur)
			{
				iter = iter->right;
			}
			if (iter->right == NULL)
			{
				iter->right = cur;
				cur = cur->left;
			}
			else
			{
				if (parent->val > cur->val)
				{
					if (!flag)
						sw_one = parent;
					sw_two = cur;
					flag = true;
				}
				iter->right = NULL;
				parent = cur;
				cur = cur->right;
			}
		}
	}
	if (flag)
		swap(sw_one->val, sw_two->val);
}
