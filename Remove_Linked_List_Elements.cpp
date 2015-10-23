#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode * dummy = new ListNode(-1);
		dummy->next = head;
		ListNode * cur = dummy->next;
		ListNode * pre = dummy;
		while (cur)
		{
			if (cur->val == val)
			{
				while (cur && cur->val == val)
					cur = cur->next;
				pre->next = cur;
			}
			if (cur == NULL)
				break;
			else
				cur = cur->next;
			pre = pre->next;

		}
		return dummy->next;
	}
	
	ListNode* removeElements2(ListNode* head, int val) {
		if (head == NULL)
			return NULL;
		head->next = removeElements2(head->next, val);
		return head->val == val ? head->next : head;
	}
};
