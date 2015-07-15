#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head->next == NULL)
		return NULL;
	ListNode* head_copy = head;
	int count = 0;
	while (head_copy->next != NULL)
	{
		head_copy = head_copy->next;
		count++;
	}
	head_copy = head;
	for (int i = 0; i < count - n; i++)
	{
		head_copy = head_copy->next;
	}
	if (count > 0 && n == 1)
	{
		head_copy->next = NULL;
		return head;
	}
	else if (count + 1 == n)
	{
		return head->next;
	}
	else
	{
		head_copy->next = head_copy->next->next;
		return head;
	}
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode **former = &(head);
    ListNode **after = &(head);
    for(int i = 0; i < n - 1; i++)
        former = &((*former)->next);
    while((*former)->next != NULL)
    {
        former = &((*former)->next);
        after = &((*after)->next);
    }
    *after = (*after)->next;
    return head;
}


int main()
{
	ListNode *ln = new ListNode(0);
	ln->next = new ListNode(1);
	ln = removeNthFromEnd(ln, 2);
	return 0;
}
