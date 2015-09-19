#include <iostream>

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
	if (root == NULL)
		return;
	TreeLinkNode* tmp = root->next;
	while (tmp != NULL && tmp->left == NULL && tmp->right == NULL)
		tmp = tmp->next;
	if (root->left != NULL)
	{
		if (root->right != NULL)
			root->left->next = root->right;
		else if (tmp != NULL)
		{
			if (tmp->left != NULL)
				root->left->next = tmp->left;
			else
				root->left->next = tmp->right;
		}
	}
	if (root->right != NULL && tmp != NULL)
	{
		if (tmp->left != NULL)
			root->right->next = tmp->left;
		else
			root->right->next = tmp->right;
	}
	
	connect(root->right);
	connect(root->left);
}

void connect2(TreeLinkNode* root)
{
	if (root == NULL)
		return;
	TreeLinkNode* tmp = root->next;
	while (tmp != NULL)
	{
		if (tmp->left != NULL)
		{
			tmp = tmp->left;
			break;
		}
		if (tmp->right != NULL)
		{
			tmp = tmp->right;
			break;
		}
		tmp = tmp->next;
	}
	if (root->left != NULL)
	{
		if (root->right != NULL)
			root->left->next = root->right;
		else
			root->left->next = tmp;
	}
	if (root->right != NULL)
		root->right->next = tmp;

	connect2(root->right);
	connect2(root->left);
}
