/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode * cur = head;
        ListNode * pre = NULL;
        while (cur)
        {
            ListNode * post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }
};
