#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		init(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (!m_st.empty())
			return true;
		else
			return false;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode * cur = m_st.top();
		int val = cur->val;
		m_st.pop();
		if (cur->right)
		{
			init(cur->right);			
		}
		return val;
	}
private:
	void init(TreeNode* root)
	{
		while (root)
		{
			m_st.push(root);
			root = root->left;
		}
	}
private:
	stack<TreeNode*> m_st;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
