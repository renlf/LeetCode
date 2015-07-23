#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* tmp = head->next->next;
	ListNode* new_head = head->next;
	head->next->next = head;
	head->next = swapPairs(tmp);
	return new_head;
}

ListNode* swapPairs2(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* new_head = head->next;
	ListNode* ptail = head;
	while (head != NULL && head->next != NULL)
	{
		ListNode* tmp = head->next->next;
		ptail->next = head->next;
		head->next->next = head;
		head->next = tmp;
		ptail = head;
		head = head->next;
	}
	return new_head;
}

int main()
{
	ListNode* first = new ListNode(0);
	ListNode* second = new ListNode(1);
	ListNode* third = new ListNode(2);
	ListNode* fourth = new ListNode(3);
	first->next = second;
	second->next = third;
	third->next = fourth;
	ListNode* result = swapPairs2(first);
	return 0;
}
