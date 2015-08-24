#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval intv_one, Interval intv_two)
{
	if (intv_one.start != intv_two.start)
		return intv_one.start < intv_two.start;
	return intv_one.end < intv_two.end;
}

vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.size() <= 1)
		return intervals;
	vector<Interval> ret;
	sort(intervals.begin(), intervals.end(), cmp);
	for (int i = 0; i < intervals.size();)
	{
		vector<Interval>::iterator former;
		int end = intervals[i].end;
		for (former = intervals.begin() + i + 1; former != intervals.end(); former++)
		{
			if (end < (*former).start)
				break;
			if (intervals[i].start <= (*former).start && end >= (*former).start)
			{
				end = max((*former).end, end);
			}
		}
		ret.push_back(Interval(intervals[i].start, end));
		i = former - intervals.begin();
	}
	return ret;
}

int main()
{
	vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
	vector<Interval> ret = merge(intervals);
	return 0;
}
