#include <vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> ret;
	for (int i = 0; i < words.size();)
	{
		int remain = maxWidth - words[i].length() - 1;
		int former = i + 1;
		string tmp = words[i];
		tmp.push_back(' ');
		while (remain > 0 && former < words.size() && words[former].length() <= remain)
		{
			remain -= (words[former].length() + 1);
			tmp += words[former];
			tmp.push_back(' ');
			former++;
		}
		tmp.pop_back();
		remain++;
		if (former == (i + 1) || former == words.size())
		{
			while (remain-- > 0)
				tmp.push_back(' ');
		}
		else
		{
			int aver = remain / (former - 1 - i);
			int left_space = remain - aver *(former - 1 - i);
			int fst_space = aver + left_space;
			int index = words[i].length();
			if (fst_space > 0)
			{
				for (int j = i; j < former - 1; j++) 
				{
					tmp.insert(tmp.begin() + index, aver, ' ');
					index += aver;
					if (left_space > 0)
					{
						tmp.insert(tmp.begin() + index, ' ');
						index++;
						left_space--;
					}
					index++;
					index += words[j + 1].length();
				}
			}
		}
		ret.push_back(tmp);
		i = former;
	}
	return ret;
}

int main()
{
	vector<string> data = {"Don't", "go", "around", "saying", "the", "world", "owes", "you", "a", "living;", "the", "world", "owes", "you", "nothing;", "it", "was", "here", "first."};
	vector<string> ret = fullJustify(data, 30);
	return 0;
}
