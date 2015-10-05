#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	if (head == NULL)
		return head;
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			slow = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
	}
	return NULL;
}
