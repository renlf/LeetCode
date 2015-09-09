#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* iter = head;
	ListNode* iter_cpy = head;
	bool flag = false;
	while (iter && iter->next)
	{
		if (iter->val == (iter->next)->val)
		{
			flag = true;
		}
		else
		{
			if (flag)
			{
				iter_cpy->next = iter->next;
				iter_cpy = iter_cpy->next;
			}
			else
				iter_cpy = iter->next;
			flag = false;
		}
		iter = iter->next;
	}
	if (flag)
		iter_cpy->next = iter->next;
	return head;
}

ListNode* deleteDuplicates2(ListNode* head) {
	ListNode* iter = head;
	while (iter && iter->next)
	{
		if (iter->val == (iter->next)->val)
		{
		    ListNode* tmp = iter->next;
		    iter->next = tmp->next;
		    delete tmp;
		}
		else
		    iter = iter->next;
	}
	return head;
}

ListNode* deleteDuplicates3(ListNode* head) {
	ListNode** iter = &head;
	while (*iter && (*iter)->next)
	{
		if ((*iter)->val == ((*iter)->next)->val)
		{
		    *iter = (*iter)->next;
		}
		else
		    iter = &((*iter)->next);
	}
	return head;
}
