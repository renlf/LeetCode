#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length())
			return false;
		unordered_map<char, char> s_map;
		unordered_map<char, char> t_map;
		for (int i = 0; i < s.length(); i++)
		{
			char schar = s[i]; 
			char tchar = t[i];
			
			if (s_map.find(schar) != s_map.end() && tchar != s_map[schar])
				return false;

			if (t_map.find(tchar) != t_map.end() && schar != t_map[tchar])
				return false;

			s_map[schar] = tchar;
			t_map[tchar] = schar;
		}
		return true;
	}
};
