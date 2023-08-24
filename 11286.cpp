#include <iostream>
#include <string.h>
#include<algorithm>
#include<sstream>
#include<math.h>
#include<cctype>
#include<stdbool.h>
#include<vector>
#include<map>
#include<queue>
#include<stdbool.h>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	priority_queue<int, vector<int>, cmp> q;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (q.empty()) {
				v.push_back(0);
			}
			else {
				v.push_back(q.top());
				q.pop();
			}
		}
		else
			q.push(x);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}