#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval>::iterator iter;
	
	for (iter = intervals.begin(); iter != intervals.end();)
	{
		if ((*iter).end < newInterval.start)
		{
			iter++;
			continue;
		}
		if ((*iter).start > newInterval.end)
		{
			intervals.insert(iter, newInterval);
			return intervals;
		}
		(*iter).start = min(newInterval.start, (*iter).start);
		if ((*iter).end >= newInterval.end)
			return intervals;
		else
		{
			(*iter).end = newInterval.end;
			vector<Interval>::iterator former;
			for (former = iter + 1; former != intervals.end(); former++)
			{
				if ((*former).start > (*iter).end)
					break;
				(*iter).end = max((*iter).end, (*former).end);
			}
			if (former != iter + 1)
				intervals.erase(iter + 1, former);
			return intervals;
		}
	}
	intervals.push_back(newInterval);
	return intervals;
}

int main()
{
	vector<Interval> intervals = { Interval(2, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };
	vector<Interval> ret = insert(intervals, Interval(0,21));
	return 0;
}
