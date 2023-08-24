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

int n;

int big = 0;

typedef struct vals {
	int target;
	int dir;
}vals;

vector<vals> v[10001];

bool visited[10001];
int dir[10001];

void DFS(int val, int result)
{
	big = max(big, result);
	visited[val] = 1;
	for (int i = 0; i < v[val].size(); i++)
	{
		int total = result;
		int data = v[val][i].target;
		if (!visited[data])
		{
			total += v[val][i].dir;
			DFS(data, total);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;
		v[s].push_back({ e, d });
		v[e].push_back({ s, d });
	}

	for (int i = 1; i <=n; i++)
	{
		DFS(i, 0);
		memset(visited, 0, sizeof(visited));
	}
	cout << big;
	
	return 0;
}