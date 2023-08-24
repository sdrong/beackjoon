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
#include<utility>

using namespace std;

int s, e;
int temp;

int BFS(int n)
{
	queue <pair <long long, long long>> q;
	q.push(make_pair(n, 1));
	while (!q.empty())
	{
		pair <long long, long long> data = q.front();
		q.pop();
		if (data.first == e)
		{
			return data.second;
		}
		if (data.first * 2 <= e)
		{
			q.push(make_pair(data.first * 2, data.second + 1));
		}
		if (data.first * 10 + 1 <= e)
		{
			q.push(make_pair(data.first * 10 + 1, data.second + 1));
		}
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> e;
	cout << BFS(s);
	return 0;
}