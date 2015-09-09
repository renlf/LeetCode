#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	ListNode * dummy = new ListNode(INT_MIN);
	dummy->next = head;
	ListNode * iter = dummy;
	ListNode * iter_cpy = iter;
	bool flag = false;
	while (iter_cpy && iter_cpy->next)
	{
		if (iter_cpy->val == (iter_cpy->next)->val)
		{
			flag = true;
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
	return dummy->next;
}
