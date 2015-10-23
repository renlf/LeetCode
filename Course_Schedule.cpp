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
	
	bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>(0));
		vector<int> visit(numCourses, 0);
		for (auto i : prerequisites)
		{
			graph[i.second].push_back(i.first);
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (visit[i] == 0 && !dfs(graph, visit, i))
				return false;
		}

		return true;
	}

private:
	bool dfs(vector<vector<int>> &graph, vector<int> & visit, int i)
	{
		visit[i] = 1;
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (visit[graph[i][j]] == 2)
				continue;
			if (visit[graph[i][j]] == 1)
				return false;
			if (!dfs(graph, visit, graph[i][j]))
				return false;
		}
		visit[i] = 2;
		return true;
	}
};
