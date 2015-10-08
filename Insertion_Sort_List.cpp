#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode * dummy = new ListNode(-1);
	ListNode * cur = head;
	while (cur)
	{
		ListNode * post = cur->next;
		
		ListNode * pre = dummy;
		while (pre->next && pre->next->val <= cur->val && pre->next != cur)
		{
			pre = pre->next;
		}

		cur->next = pre->next;
		pre->next = cur;

		cur = post;
	}

	return dummy->next;
}
