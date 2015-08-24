#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
	if (head == NULL || k == 0)
		return head;
	ListNode* former = head;
	int total_size = 0;
	while (former != NULL)
	{
		total_size++;
		former = former->next;
	}
	if (k % total_size == 0)
		return head;
	former = head;
	int remain = k % total_size;
	while (total_size > remain + 1)
	{
		former = former->next;
		total_size--;
	}
	ListNode* new_tail = former;
	ListNode* new_head = former->next;
	new_tail->next = NULL;
	former = new_head;
	while (former->next != NULL)
	{
		former = former->next;
	}
	former->next = head;
	return new_head;
}

int main()
{
	ListNode *one = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *three = new ListNode(3);
	ListNode *four = new ListNode(4);
	ListNode *five = new ListNode(5);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = NULL;
	ListNode* ret = rotateRight(one, 2);
	return 0;
}
