#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
	ListNode * new_head = new ListNode(0);
	ListNode * new_part = new ListNode(0);
	ListNode * ret = new_head;
	ListNode * part = new_part;
	while (head)
	{
		if (head->val < x)
		{
			new_head->next = head;
			new_head = new_head->next;
		}
		else
		{
			new_part->next = head;
			new_part = new_part->next;
		}
		head = head->next;
	}
	new_part->next = NULL;
	new_head->next = part->next;
	return ret->next;
}

int main()
{
	ListNode * l1 = new ListNode(2); 
	ListNode * l2 = new ListNode(1);
	l1->next = l2;
	ListNode *ret = partition(l1, 2);
	return 0;
}
