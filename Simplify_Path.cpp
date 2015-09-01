#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path) {
	vector<string> st;
	for (int i = 0; i < path.length();)
	{
		string tmp = "";
		if (path[i] == '/')
		{
			i++;
			continue;
		}
		if (path[i] == '.')
		{
			int i_cpy = i;
			i++;
			while (i < path.size() && path[i] == '.')
				i++;
			if (i_cpy + 1 == i || i_cpy + 2 == i)
			{
				if (i == path.size() || (i < path.length() && path[i] == '/'))
				{
					if (i_cpy + 2 == i && st.size() > 0)
						st.pop_back();
					continue;
				}
			}
			tmp += path.substr(i_cpy, i - i_cpy);
		}
		while (i < path.length() && path[i] != '.' && path[i] != '/')
		{
			tmp.push_back(path[i]);
			i++;
		}
		if (tmp != "")
			st.push_back(tmp);
	}
	if (st.size() == 0)
		return "/";
	string ret = "";
	for (int i = 0; i < st.size(); i++)
		ret = ret + "/" + st[i];
	return ret;
}

int main()
{
	string ret = simplifyPath("/.headen/");
	return 0;
}
