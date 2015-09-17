#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bt_BST(ListNode* head, int start, int end)
{
	if (start > end)
		return NULL;

	int mid = (start + end) / 2;
	int mid_cpy = mid;

	ListNode* iter = head;
	while (mid_cpy-- > 1)
		iter = iter->next;

	TreeNode* root = new TreeNode(iter->val);
	root->left = bt_BST(head, start, mid - 1);
	root->right = bt_BST(iter->next, 1, end - mid);

	return root;
}

TreeNode* sortedListToBST(ListNode* head) {
	if (head == NULL)
		return NULL;
	int count = 0;
	ListNode* iter = head;
	while (iter != NULL)
	{
		iter = iter->next;
		count++;
	}
	return bt_BST(head, 1, count);
}
