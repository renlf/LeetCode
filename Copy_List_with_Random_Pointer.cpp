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
