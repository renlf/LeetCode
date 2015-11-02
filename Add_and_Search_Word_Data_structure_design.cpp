include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {

	}
	TrieNode(char ch) {
		c = ch;
		isend = false;
	}
	TrieNode* next_node(char c)
	{
		for (auto node : child)
		{
			if (node->c == c)
				return node;
		}
		return NULL;
	}
public:
	char c;
	bool isend;
	vector<TrieNode*> child;
};

class WordDictionary {
public:
	WordDictionary()
	{
		root = new TrieNode();
	}
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode * cur = root;
		for (int i = 0; i < word.length(); i++)
		{
			TrieNode * post = cur->next_node(word[i]);
			if (post != NULL)
				cur = post;
			else
			{
				TrieNode* tmp = new TrieNode(word[i]);
				cur->child.push_back(tmp);
				cur = tmp;
			}
		}
		cur->isend = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		TrieNode * cur = root;
		return bt_search(cur, word, 0);
	}

private:
	bool bt_search(TrieNode * cur, string word, int i)
	{
		bool ret = false;
		for (; i < word.length(); i++)
		{
			if (word[i] != '.')
			{
				cur = cur->next_node(word[i]);
				if (cur == NULL)
					return false;
			}
			else if (i + 1 <= word.length() && cur->child.size() > 0)
			{
				for (int k = 0; k < cur->child.size(); k++)
					ret = ret || bt_search(cur->child[k], word, i + 1);
				break;
			}
			else
				return false;
		}
		if (i == word.length())
			return ret || cur->isend;
		
		return ret;
	}

private:
	TrieNode * root;
};
