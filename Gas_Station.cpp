#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int remain = 0;
	int pos = 0;
	for (int i = 0, sum = 0; i < gas.size(); i++)
	{
		sum += gas[i] - cost[i];
		remain += gas[i] - cost[i];
		if (sum < 0)
		{
			pos = i + 1;
			sum = 0;
		}
	}
	return remain >= 0 ? pos : -1;
}
