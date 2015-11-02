#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class TrieNode{
public:
	TrieNode(){}
	TrieNode(char ch)
	{
		c = ch;
		isend = false;
	}
	TrieNode* next_node(char ch)
	{
		for (auto node : child)
		{
			if (node->c == ch)
				return node;
		}
		return NULL;
	}
public:
	char c;
	bool isend;
	vector<TrieNode*> child;
};

class Trie
{
public:
	Trie(){
		root = new TrieNode();
	}
	void insert(string word)
	{
		TrieNode * cur = root;
		for (int i = 0; i < word.length(); i++)
		{
			TrieNode * post = cur->next_node(word[i]);
			if (post != NULL)
				cur = post;
			else
			{
				post = new TrieNode(word[i]);
				cur->child.push_back(post);
				cur = post;
			}
		}
		cur->isend = true;
	}
	bool search(string word)
	{
		TrieNode * cur = root;
		for (int i = 0; i < word.length(); i++)
		{
			cur = cur->next_node(word[i]);
			if (cur == NULL)
				return false;
		}
		return cur->isend;
	}
	bool prefix(string word)
	{
		TrieNode * cur = root;
		for (int i = 0; i < word.length(); i++)
		{
			cur = cur->next_node(word[i]);
			if (cur == NULL)
				return false;
		}
		return true;
	}
public:
	TrieNode * root;
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		trie = new Trie();
		for (auto word : words)
			trie->insert(word);
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				string str = "";
				bt_find(board, str, i, j);
			}
		}
		for (auto word : store)
			ret.push_back(word);
		return ret;
	}
private:
	void bt_find(vector<vector<char>> & board, string str, int i, int j)
	{
		if (i < 0 || j < 0 || i == board.size() || j == board[0].size())
			return;
		str.push_back(board[i][j]);
		if (trie->search(str) == true)
			store.insert(str);
		if (trie->prefix(str) == true)
		{
			char tmp = board[i][j];
			board[i][j] = '*';
			bt_find(board, str, i - 1, j);
			bt_find(board, str, i + 1, j);
			bt_find(board, str, i, j - 1);
			bt_find(board, str, i, j + 1);
			board[i][j] = tmp;
		}
	}
private:
	vector<string> ret;
	Trie *trie;
	unordered_set<string> store;
};
