#include <string>
#include <iostream>

using namespace std;

string countAndSay(int n) {
	string nums = "1";
	for (int i = 1; i < n; i++)
	{
		char tmp = nums[nums.length() - 1];
		string new_nums = "";
		int count = 1;
		for (int j = nums.length() - 2; j >= 0; j--)
		{
			if (nums[j] == tmp)
			{
				count++;
			}
			else
			{
				new_nums.insert(0, string(1, tmp));
				new_nums.insert(0, to_string(count));
				count = 1;
				tmp = nums[j];
			}
		}
		new_nums.insert(0, string(1, tmp));
		new_nums.insert(0, to_string(count));
		nums = new_nums;
	}
	return nums;
}

int main()
{
	for (int i = 0; i < 20; i++)
	{
		string result = countAndSay(i);
		cout << result << endl;
	}
	
	return 0;
}
