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

using namespace std;

bool visited[10001];

int s, e;

int check[10000];

void primeNumberSieve()
{
	check[0] = check[1] = true;
	for (int i = 2; i < sqrt(9999); i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= 9999; j += i) {
				check[j] = true;
			}
		}
	}
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	visited[s] = 1;
	while (!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == e)
		{
			cout << cnt << "\n";
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				string s = to_string(num);
				s[i] = '0' + j;
				int val = stoi(s);
				if (check[val])
					continue;
				if (visited[val])
					continue;
				if (val < 1000 || val >= 10000)
					continue;
				visited[val] = 1;
				q.push(make_pair(val, cnt + 1));
			}
		}
	}
	cout << "Impossible\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	primeNumberSieve();
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		BFS();
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}