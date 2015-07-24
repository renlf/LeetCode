#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k == 1 || head == NULL || head->next == NULL)
		return head;
	ListNode* pre = head;
	ListNode* tail = head;
	int ret = 1;
	while (pre->next != NULL)
	{
		ret++;
		pre = pre->next;
	}
	if (k > ret)
		return head;

	pre = head;
	head = head->next;
	ret = k;
	while (head != NULL && k > 1)
    {
		ListNode* tmp = head->next;
		head->next = pre;
		tail->next = tmp;
		pre = head;
		head = tmp;
		k--;
	}
	if (head != NULL)
	{
		tail->next = reverseKGroup(head, ret);
	}
	return pre;
}

ListNode* reverseKGroup2(ListNode* head, int k) {
	if (k == 1 || head == NULL || head->next == NULL)
		return head;
	ListNode* pre = head;
	ListNode* tail = head;
	ListNode* iter = head;
	int ret = k;

	head = head->next;
	while (iter != NULL && ret > 1)
    {
		ret--;
        iter = iter->next;
		if (ret == 1 && iter != NULL)
		{
			ret = k;
			while (ret > 1)
			{
				ListNode* tmp = head->next;
				head->next = pre;
				tail->next = tmp;
				pre = head;
				head = tmp;
				ret--;
			}
			break;
		}
	}
	if (head != NULL)
	{
		tail->next = reverseKGroup2(head, k);
	}
	return pre;
}

ListNode *reverseList(ListNode*head, ListNode*last_tail) {
	ListNode *next_node = head->next;
	ListNode *res = head;
	while (next_node) {
		ListNode *tmp = next_node->next;
		next_node->next = head;
		head = next_node;
		next_node = tmp;
	}
	last_tail->next = head;
	return res;
}

ListNode *reverseKGroup3(ListNode *head, int k) {
	ListNode *newHead = new ListNode(0);
	newHead->next = head;

	int cnt = 0;
	ListNode *cur_node = head;
	ListNode *last_tail = newHead;
	while (cur_node) {
		cnt++;
		if (cnt == k) {
			ListNode *cp = cur_node->next;

			cur_node->next = NULL;
			last_tail = reverseList(last_tail->next, last_tail);
			last_tail->next = cp;

			cur_node = cp;
			cnt = 0;
			continue;
		}
		cur_node = cur_node->next;
	}
	return newHead->next;
}

int main()
{
	ListNode* first = new ListNode(0);
	ListNode* second = new ListNode(1);
	ListNode* third = new ListNode(2);
	ListNode* fourth = new ListNode(3);
	first->next = second;
	//second->next = third;
	//third->next = fourth;
	ListNode* result = reverseKGroup2(first, 3);
}
