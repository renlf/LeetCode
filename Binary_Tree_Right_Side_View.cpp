#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			ret.push_back(q.back()->val);
			int count = q.size();
			while (count)
			{
				TreeNode* tmp = q.front();
				if (tmp->left != NULL)
					q.push(tmp->left);
				if (tmp->right != NULL)
					q.push(tmp->right);
				q.pop();
				count--;
			}
		}
		return ret;
	}
};
