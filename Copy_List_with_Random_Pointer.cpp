#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)
		return head;
	unordered_map<RandomListNode*, RandomListNode*> ret;
	RandomListNode * p = head;
	RandomListNode * np = new RandomListNode(p->label);
	ret[head] = np;
	while (p != NULL)
	{
		if (p->next != NULL)
		{
			if (ret.find(p->next) == ret.end())
			{
				RandomListNode *tmp = new RandomListNode(p->next->label);
				ret[p->next] = tmp;
				np->next = tmp;
			}
			else
			{
				np->next = ret[p->next];
			}
		}
		if (p->random != NULL)
		{
			if (ret.find(p->random) == ret.end())
			{
				RandomListNode * tmp = new RandomListNode(p->random->label);
				ret[p->random] = tmp;
				np->random = tmp;
			}
			else
			{
				np->random = ret[p->random];
			}
		}
		p = p->next;
		np = np->next;
	}
	return ret[head];
}

RandomListNode *copyRandomList2(RandomListNode *head) {
	if (head == NULL)
		return head;

	RandomListNode * cur = head;
	while (cur != NULL)
	{
		RandomListNode * new_node = new RandomListNode(cur->label);
		new_node->next = cur->next;
		cur->next = new_node;
		cur = new_node->next;
	}
	cur = head;
	while (cur != NULL)
	{
		if (cur->random != NULL)
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}
	cur = head;
	RandomListNode* dummy = new RandomListNode(-1);
	dummy->next = cur->next;
	while (cur != NULL)
	{
		RandomListNode* cpy_node = cur->next;
		cur->next = cpy_node->next;
		if (cpy_node->next != NULL)
		{
			cpy_node->next = cpy_node->next->next;
		}
		cur = cur->next;
	}
	return dummy->next;
}
