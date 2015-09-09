#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode * iter = head;
	ListNode * iter_cpy = iter;
	bool flag = false;
	bool first = false;
	while (iter_cpy && iter_cpy->next)
	{
		if (iter_cpy->val == (iter_cpy->next)->val)
		{
			flag = true;
			if (iter_cpy == head)
				first = true;
		}
		else
		{
			if (flag)
			{
				iter->next = iter_cpy->next;
				flag = false;
			}
			else
				iter = iter_cpy;
		}
		iter_cpy = iter_cpy->next;
	}
	if (flag)
		iter->next = iter_cpy->next;
	if (first)
		return head->next;
	else
		return head;
}
