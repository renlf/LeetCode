#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    const int count = s.length();
    if(count == 0)
    {
        return 0;
    }
    vector<int> repeat_array;
    repeat_array.resize(count, 0);
    int max_repeat = 1;
    int max_index = 0;
    //int * repeat_array = new int[count];
    for(int i = 0; i < count; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(s[i] == s[j])
            {
                if (repeat_array[j - 1] != 0)
                {
                    int tmp = repeat_array[j - 1] + 1;
                    repeat_array[j] = tmp;
                    if(max_repeat < tmp)
                    {
                        max_repeat = tmp;
                        max_index = i;
                    }
                }
                else
                {
                    repeat_array[j] = 1;
                }
            }
            else
            {
                repeat_array[j] = 0;
            }
        }
    }
    int all_count = 0;
    int start_index = max_index - (max_repeat - 1);
    for(int i = start_index; i <= max_index; i++)
    {
        if(s[start_index] != s[i])
        {
            break;
        }
        all_count++;
    }
    if(all_count > max_repeat)
    {
        return all_count;
    }
    else
    {
        return max_repeat;
    }

}

int lengthOfLongestSubstring2(string s) {
	const int count = s.length();
	if (count == 0)
	{
		return 0;
	}
	vector<int> repeat_array;
	repeat_array.resize(count, 0);
	int max_repeat = 1;
	bool is_repeat = false;
	for (int i = 0; i < count / 2; i++)
	{
		string sub1 = s.substr(0, i + 1);
		string sub2 = s.substr(i + 1, i + 1);
		if ((sub1 == sub2) && (i + 1 >= max_repeat))
		{
			max_repeat = i + 1;
			is_repeat = true;
		}
		else
		{
			break;
		}
	}
	if (is_repeat == true)
	{
		return max_repeat;
	}
	else
		return count;
}

int lengthOfLongestSubstring3(string s)
{
	unordered_map<char, int> repeat_map;
	unordered_map<char, int>::iterator iter;
	int max_unrepeat = 0;
	int tmp_unrepeat = 0;
	bool had_repeat = false;
	for (int i = 0; i < s.length(); i++)
	{
		had_repeat = false;
		repeat_map[s[i]] = i;
		int j = i + 1;
		for (; j < s.length(); j++)
		{
			if ((iter = repeat_map.find(s[j])) == repeat_map.end())
			{
				repeat_map[s[j]] = j;
			}
			else
			{
				had_repeat = true;
				break;
			}
		}

		tmp_unrepeat = repeat_map.size();
		if (tmp_unrepeat > max_unrepeat)
		{
			max_unrepeat = tmp_unrepeat;
		}

		if (had_repeat == true)
		{
			for (int k = i; k <= j; k++)
			{
				if (s[k] != s[j] && (iter = repeat_map.find(s[k])) != repeat_map.end())
				{
					repeat_map.erase(iter);
				}
			}
		}
	}

	return max_unrepeat;
}

int lengthOfLongestSubstring4(string s)
{
    int str_len = s.length();
    if(str_len == 0)
    {
        return 0;
    }
    unordered_map<char, int> repeat;
    unordered_map<char, int>::iterator iter;
    int max_repeat = 0;
    int start_index = 0;
    for(int i = 0; i < str_len; i++)
    {
        if((iter = repeat.find(s[i])) == repeat.end())
        {
            repeat[s[i]] = i;
            int tmp_repeat = i - start_index + 1;
            if(max_repeat < tmp_repeat)
            {
                max_repeat = tmp_repeat;
            }
        }
        else
        {
            char double_char = iter->first;
            int double_index = iter->second;
            for(int j = start_index; j < double_index; j++)
            {
                repeat.erase(repeat.find(s[j]));
            }
            start_index = double_index + 1;
            repeat[s[double_index]] = i;
        }
    }
    return max_repeat;
}

int main()
{
	//string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	string s = "ohomm";
	int count = lengthOfLongestSubstring4(s);
	int a;
	cin >> a;
}
