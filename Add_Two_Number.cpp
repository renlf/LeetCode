#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if ((l1 == NULL) || (l2 == NULL))
	{
		return NULL;
	}
	ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
	int carry = 0;
	int tmp = l1->val + l2->val;
	if (tmp >= 10)
	{
		carry = 1;
	}
	result->val = tmp % 10;

	ListNode* forword;
	forword = result;

	while (((l1->next != NULL) || (l2->next != NULL)) || (carry == 1))
	{
		forword->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		if ((l1->next == NULL) && (l2->next == NULL))
		{
			forword->next->val = carry;
			forword->next->next = NULL;
			break;
		}
		else if (l1->next == NULL)
		{
			tmp = carry + l2->next->val;
			l2 = l2->next;
		}
		else if (l2->next == NULL)
		{
			tmp = carry + l1->next->val;
			l1 = l1->next;
		}
		else
		{
			tmp = l1->next->val + l2->next->val + carry;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (tmp >= 10)
			carry = 1;
		else
			carry = 0;

		forword->next->val = tmp % 10;
		forword->next->next = NULL;
		forword = forword->next;
	}
	return result;
}

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
{
	if ((l1 == NULL) || (l2 == NULL))
	{
		return NULL;
	}
	ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
	ListNode * forword;
	forword = result;
	int carry = 0;
	int tmp = 0;
	bool init = true;
	while (((l1 != NULL) || (l2 != NULL)) || (carry == 1))
	{
		if (init == false)
		{

			forword->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			forword = forword->next;
		}

		if ((l1 == NULL) && (l2 == NULL))
		{
			forword->val = carry;
			forword->next = NULL;
			break;
		}
		else if (l1 == NULL)
		{
			tmp = carry + l2->val;
			l2 = l2->next;
		}
		else if (l2 == NULL)
		{
			tmp = carry + l1->val;
			l1 = l1->next;
		}
		else
		{
			tmp = l1->val + l2->val + carry;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (tmp >= 10)
			carry = 1;
		else
			carry = 0;

		forword->val = tmp % 10;
		forword->next = NULL;
		//forword = forword->next;

		init = false;
	}
	return result;
}

ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2)
{
    if((l1 == NULL) || (l2 == NULL))
    {
        return NULL;
    }
    ListNode result = ListNode(0);
    ListNode *forword = &result;
    int carry = 0;
    while((l1 != NULL) || (l2 != NULL))
    {
        int l1_value = (l1 == NULL) ? 0 : l1->val;
        int l2_value = (l2 == NULL) ? 0 : l2->val;
        int tmp_value = l1_value + l2_value + carry;
        forword->next = new ListNode(tmp_value % 10);
        carry = tmp_value / 10;
        l1 = (l1 == NULL) ? NULL : l1->next;
        l2 = (l2 == NULL) ? NULL : l2->next;
        forword = forword->next;
    }
    if(carry == 1)
    {
        forword->next =  new ListNode(carry);
    }
    return result.next;
}

int main()
{

	ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l3->val = 9;
	l3->next = NULL;

	ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->val = 9;
	l1->next = l3;

	ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2->val = 1;
	l2->next = NULL;
	ListNode *result = addTwoNumbers3(l2,l1);
	int a;
	cin >> a;
	return 0;
}
