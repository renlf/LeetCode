#include <string>
#include <vector>
#include <iostream>

using namespace std;

string zigzag(string s, int numRows)
{
    int str_len = s.length();
    vector<string> sub_str;
    sub_str.resize(numRows, "");
    int zz_len = 2*numRows - 2;
    if(zz_len == 0)
    {
        return s;
    }
    for(int i = 0; i < str_len; i++)
    {
        int tmp_mod = i % zz_len;
        if(tmp_mod < numRows)
        {
            sub_str[tmp_mod] += s[i];
        }
        else
        {
            int index = numRows - 2 - (tmp_mod % numRows);
            sub_str[index] += s[i];
        }
    }
    string result = "";
    for (int i = 0; i < numRows; i++)
    {
        result += sub_str[i];
        cout << sub_str[i] << endl;
    }

    return result;
}

int main()
{
    string s = "PAYPALISHIRING";
    s = zigzag(s, 3);
    cout << s << endl;
    cout << "PAHNAPLSIIGYIR" << endl;
    string s2 = "ABCD";
    s = zigzag(s2, 2);
    cout << s << endl;
    cout << "ACBD" << endl;
    return 0;
}
