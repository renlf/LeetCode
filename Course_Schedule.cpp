#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>(0));
		vector<int> indgree(numCourses, 0);
		for (auto i : prerequisites)
		{			
			graph[i.second].push_back(i.first);
			indgree[i.first]++;
		}
		queue<int> q;
		for (int i = 0; i < indgree.size(); i++)
		{
			if (indgree[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int k = q.front();
			q.pop();
			for (int i = 0; i < graph[k].size(); i++)
			{
				if (--indgree[graph[k][i]] == 0)
					q.push(graph[k][i]);
			}
		}
		for (int i = 0; i < indgree.size(); i++)
		{
			if (indgree[i] != 0)
				return false;
		}
		return true;
	}
};
