#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point>& points) {
	if (points.size() == 0)
		return 0;
	int max_num = 0;
	unordered_map<double, int> record;
	for (int i = 0; i < points.size(); i++)
	{
		int same = 0;
		record.clear();
		for (int j = 0; j < points.size(); j++)
		{
			if (points[i].x == points[j].x)
			{
				if (points[i].y == points[j].y)
				{
					same++;
				}
				else
				{
					record[numeric_limits<double>::max()]++;
				}
			}
			else
			{
				double rate = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
				record[rate]++;
			}
		}
		max_num = max(same, max_num);
		unordered_map<double, int>::iterator iter;
		for (iter = record.begin(); iter != record.end(); iter++)
		{
			if (iter->second + same > max_num)
				max_num = iter->second + same;
		}
	}
	return max_num;
}
