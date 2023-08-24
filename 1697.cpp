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

int n, n2;

int result[100001];
int visited[100001];

void BFS(int v)
{
	queue<int> q;
	visited[v] = true;
	result[v] = 0;
	q.push(v);
	while (!q.empty())
	{
		int num = q.front();
		if (num == n2)
			break;
		q.pop();
		
		if (visited[num + 1] == 0 && num + 1 < 100001)
		{
			visited[num + 1] = true;
			result[num + 1] = result[num] + 1;
			q.push(num + 1);
		}
		if (visited[num * 2] == 0 && num * 2 < 100001)
		{
			visited[num * 2] = true;
			result[num * 2] = result[num] + 1;
			q.push(num * 2);
		}
		if (visited[num - 1] == 0 && num - 1 >= 0)
		{
			visited[num - 1] = true;
			result[num - 1] = result[num] + 1;
			q.push(num - 1);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> n2;
	BFS(n);
	cout << result[n2];
	return 0;
}