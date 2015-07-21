#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *list = new ListNode(0);
	ListNode *ln = list;
	while ((l1 != NULL) && (l2 != NULL))
	{
		if (l1->val < l2->val)
		{
			ln->next = l1;
			l1 = l1->next;
		}
		else
		{
			ln->next = l2;
			l2 = l2->next;
		}
		ln = ln->next;
	}
	if (l1 != NULL)
		ln->next = l1;
	if (l2 != NULL)
		ln->next = l2;

	return list->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0)
		return NULL;
	if (lists.size() == 1)
		return lists[0];

	vector<ListNode*> tmp_list;
	int i;
	for (i = 0; i + 1 < lists.size(); i+=2)
	{
		tmp_list.push_back(mergeTwoLists(lists[i], lists[i + 1]));
	}

	if (i < lists.size())
		tmp_list.push_back(lists[lists.size() - 1]);

	return mergeKLists(tmp_list);
}

ListNode* mergeKLists2(vector<ListNode*>& lists)
{
	if (lists.size() == 0)
		return NULL;

	ListNode* result = lists[0];
	for (int i = 1; i < lists.size(); i++)
	{
		result = mergeTwoLists(result, lists[i]);
	}
	return result;
}

ListNode* doMerge(vector<ListNode*>& lists, int left, int right)
{
	if (left == right)
		return lists[left];
	int mid = (left + right) / 2;

	ListNode* l1 = doMerge(lists, left, mid);
	ListNode* l2 = doMerge(lists, mid + 1, right);

	return mergeTwoLists(l1, l2);
}

ListNode* mergeKLists3(vector<ListNode*>& lists)
{
	if (lists.size() == 0)
		return NULL;
	return doMerge(lists, 0, lists.size() - 1);
}

ListNode* mergeKLists4(vector<ListNode*>& lists)
{
	if (lists.size() == 0)
		return NULL;

	int end = lists.size() - 1;
	while (end > 0)
	{
		int begin = 0;
		while (begin < end)
		{
			lists[begin] = mergeTwoLists(lists[begin], lists[end]);
			begin++;
			end--;
		}
	}
	return lists[0];
}

struct cmp{
	bool operator() (ListNode* p, ListNode *q) const
	{
		return p->val > q->val;
	}
};

ListNode* mergeKLists5(vector<ListNode*>& lists)
{
	priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
	ListNode *dummy = new ListNode(0);
	ListNode *tail = dummy;

	for (int i = 0; i < lists.size(); i++)
	{
		if (lists[i])
			pq.push(lists[i]);
	}

	while (!pq.empty())
	{
		tail->next = pq.top();
		tail = tail->next;
		pq.pop();
		if (tail->next)
			pq.push(tail->next);
	}

	return dummy->next;
}
