#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * findMid(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

ListNode* reverse(ListNode* head)
{
	ListNode* cur = head;
	ListNode* pre = NULL;
	while (cur)
	{
		ListNode* post = cur->next;
		cur->next = pre;
		pre = cur;
		cur = post;
	}
	return pre;
}

void reorderList(ListNode* head) {
	if (head == NULL)
		return;
	ListNode * mid = findMid(head);
	ListNode * tail = reverse(mid);
	ListNode * cur = head;
	while (cur != mid && cur->next != tail)
	{
		ListNode * cpost = cur->next;
		ListNode * tpost = tail->next;
		cur->next = tail;
		tail->next = cpost;
		cur = cpost;
		tail = tpost;
	}
	mid->next = NULL;
}
