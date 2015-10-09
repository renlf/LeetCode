#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode * a = headA;
	ListNode * b = headB;

	if (a == NULL || b == NULL)
		return NULL;

	while (a && b && a != b)
	{
		a = a->next;
		b = b->next;
		if (a == b)
			return a;
		if (a == NULL)
			a = headB;
		if (b == NULL)
			b = headA;
	}

	return a;
}
