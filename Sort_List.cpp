include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeList(ListNode* h1, ListNode* h2)
{
	ListNode * dummy = new ListNode(-1);
	ListNode * cur = dummy;
	while (h1 && h2)
	{
		if (h1->val <= h2->val)
		{
			cur->next = h1;
			h1 = h1->next;
		}
		else
		{
			cur->next = h2;
			h2 = h2->next;
		}
		cur = cur->next;
	}
	if (h1)
		cur->next = h1;
	if (h2)
		cur->next = h2;

	return dummy->next;
}

ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow;
	slow = slow->next;
	fast->next = NULL;

	ListNode *h1 = sortList(head);
	ListNode *h2 = sortList(slow);
	return mergeList(h1, h2);
}
