#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (head == NULL || m >= n || m < 1)
		return head;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	head = dummy;
	for (int i = 1; i < m; i++)
	{
		head = head->next;
	}
	ListNode * store = head;
	head = head->next;
	ListNode * r_tail = head;
	ListNode * cur = head->next;
	for (int i = 0; i < n - m; i++)
	{
		ListNode * tmp = cur->next;
		cur->next = head;
		head = cur;
		cur = tmp;
	}
	store->next = head;
	r_tail->next = cur;
	return dummy->next;
}

int main()
{
	ListNode * one = new ListNode(1);
	ListNode * two = new ListNode(2);
	ListNode * three = new ListNode(3);
	ListNode * four = new ListNode(4);
	ListNode * five = new ListNode(5);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = NULL;
	ListNode * ret = reverseBetween(one, 2, 4);
	return 0;
}
