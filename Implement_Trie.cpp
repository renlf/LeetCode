#include <string>
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

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode * cur = root;

		for (int i = 0; i < word.length(); i++)
		{
			TrieNode * post = cur->next_node(word[i]);
			if (post != NULL)
				cur = post;
			else
			{
				TrieNode* new_node = new TrieNode(word[i]);
				cur->child.push_back(new_node);
				cur = new_node;
			}
		}

		cur->isend = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode * cur = root;
		for (int i = 0; i < word.length(); i++)
		{
			cur = cur->next_node(word[i]);
			if (cur == NULL)
				return false;
		}
		return cur->isend;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode * cur = root;
		for (int i = 0; i < prefix.length(); i++)
		{
			cur = cur->next_node(prefix[i]);
			if (cur == NULL)
				return false;
		}
		return true;
	}

private:
	TrieNode* root;
};
