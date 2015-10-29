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
};
