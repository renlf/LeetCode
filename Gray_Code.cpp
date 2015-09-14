#include <vector>

using namespace std;

vector<int> grayCode(int n) {
	vector<int> ret;
	int size = 1 << n;
	for (int i = 0; i < size; i++) {
		ret.push_back((i >> 1) ^ i);
	}
	return ret;
}

int main()
{
	vector<int> ret = grayCode(2);
	return 0;
}
