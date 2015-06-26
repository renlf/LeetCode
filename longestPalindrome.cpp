#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestPalindrome(string s) {
	int str_len = s.length();
	if (str_len == 1)
	{
		return s;
	}
	vector< int > d;
	d.resize(str_len, 0);
	int max_len = 0;
	int start_index = 0;
	for (int i = 0; i < str_len - 1; i++)
	{
		int tmp_i = -1;
		int tmp_j = str_len;
		if (i > 0 && s[i - 1] == s[i + 1] )
		{
			d[i] = 1;
			tmp_i = i - 1;
			tmp_j = i + 1;
			for (; tmp_i >= 0 && tmp_j < str_len; tmp_i--, tmp_j++)
			{
				if (s[tmp_i] == s[tmp_j])
				{
					d[tmp_i] = d[tmp_i + 1] + 2;

					if (d[tmp_i] > max_len)
					{
						max_len = d[tmp_i];
						start_index = tmp_i;
					}
				}
				else
					break;
			}
		}
		if (s[i] == s[i+1])
		{
			d[i] = 2;
			tmp_i = i - 1;
			tmp_j = i + 2;
			for (; tmp_i >= 0 && tmp_j < str_len; tmp_i--, tmp_j++)
			{
				if (s[tmp_i] == s[tmp_j])
				{
					d[tmp_i] = d[tmp_i + 1] + 2;

					if (d[tmp_i] > max_len)
					{
						max_len = d[tmp_i];
						start_index = tmp_i;
					}
				}
				else
					break;
			}
		}
		if (d[i] > max_len)
		{
			max_len = d[i];
			start_index = i;
		}
	}

	return s.substr(start_index, max_len);
}

string longestPalindrome2(string s)
{
    int str_len = s.length();

    string s_extend = "*";
    for(int i = 0; i < str_len; i++)
    {
        s_extend += s[i];
        s_extend += "*";
    }

    int max_len = 1;
    int start_index = 0;
    int ext_len = 2*str_len + 1;
    vector<int> d;
    d.resize(ext_len, 0);

    for(int i = 1; i < ext_len; i++)
    {
        int tmp_f = -1;
        int tmp_b = -1;
        if(s_extend[i] == '*')
        {
            tmp_f = i - 1;
            tmp_b = i + 1;
        }
        else
        {
            tmp_f = i - 2;
            tmp_b = i + 2;
        }
        d[i] = 1;
        for(;tmp_f >= 0 && tmp_b < ext_len; tmp_f-=2, tmp_b+=2)
        {
            if(s_extend[tmp_f] == s_extend[tmp_b])
            {
                d[tmp_f] = d[tmp_f + 2] + 2;
                if(d[tmp_f] > max_len)
                {
                    max_len = d[tmp_f];
                    start_index = tmp_f;
                }
            }
            else
                break;
        }
    }
    start_index = start_index / 2;
    return s.substr(start_index, max_len);
}

string longestPalindrome3(string s)
{
    int str_len = s.length();
    bool d[str_len][str_len];
    memset(d, false, str_len * str_len * sizeof(bool));
    int max_len = 0;
    int start_index = 0;

    for(int i = 0; i < str_len; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            d[j][i] = ((s[j] == s[i]) && (i - j < 2 || d[j + 1][i - 1]));
            if((d[j][i] == true) && (max_len < (i - j + 1)))
            {
                max_len = i - j + 1;
                start_index = j;
            }
        }
        d[i][i] = true;
    }

    return s.substr(start_index, max_len);
}

int main()
{
	string s = "bppbsooos";
	s = longestPalindrome2(s);
	cout << s << endl;
	return 0;
}
