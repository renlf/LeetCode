#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ret;
		vector<vector<int>> graph(numCourses);
		vector<int> indgree(numCourses, 0);
		queue<int> q;
		for (auto item : prerequisites)
		{
			graph[item.second].push_back(item.first);
			indgree[item.first]++;
		}
		for (int i = 0; i < indgree.size(); i++)
		{
			if (indgree[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int k = q.front();
			q.pop();
			ret.push_back(k);
			for (int i = 0; i < graph[k].size(); i++)
			{
				if (--indgree[graph[k][i]] == 0)
					q.push(graph[k][i]);
			}
		}
		for (int i = 0; i < indgree.size(); i++)
		{
			if (indgree[i] != 0)
			{
				ret.clear();
				break;
			}
		}
		return ret;
	}
	vector<int> findOrder2(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<vector<int>> graph(numCourses);
		vector<int> visit(numCourses, 0);
		vector<int> order;
		for (auto item : prerequisites)
		{
			graph[item.second].push_back(item.first);
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (visit[i] == 0 && !dfs(graph, visit, order, i))
			{
				order.clear();
				break;
			}
		}
		reverse(order.begin(), order.end());
		return order;
	}
private:
	bool dfs(vector<vector<int>> &graph, vector<int> &visit, vector<int> &order, int i)
	{
		visit[i] = 1;
		for (int j = 0; j < graph[i].size(); j++)
		{
			int k = graph[i][j];
			if (visit[k] == 2)
				continue;
			if (visit[k] == 1)
				return false;
			if (!dfs(graph, visit, order, k))
				return false;
		}
		visit[i] = 2;
		order.push_back(i);
		return true;
	}
};
