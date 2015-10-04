#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL)
		return node;
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> ret;
	queue<UndirectedGraphNode*> que;
	que.push(node);
	ret[node] = new UndirectedGraphNode(node->label);
	while (!que.empty())
	{
		UndirectedGraphNode* cur = que.front();
		que.pop();
		for (int i = 0; i < cur->neighbors.size(); i++)
		{
			if (ret.find(cur->neighbors[i]) == ret.end())
			{
				UndirectedGraphNode* cpy = new UndirectedGraphNode(cur->neighbors[i]->label);
				ret[cur->neighbors[i]] = cpy;
				ret[cur]->neighbors.push_back(cpy);
				que.push(cur->neighbors[i]);
			}
			else
			{
				ret[cur]->neighbors.push_back(ret[cur->neighbors[i]]);
			}
		}
	}
	return ret[node];
}
