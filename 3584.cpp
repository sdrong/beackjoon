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

int parent[10001];
bool visited[10001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		for (int j = 0; j < c-1; j++)
		{
			int s, e;
			cin >> s >> e;
			parent[e] = s;
		}
		int a, b;
		cin >> a >> b;
		visited[a] = 1;
		while (parent[a])
		{
			a = parent[a];
			visited[a] = 1;
		}
		while (1)
		{
			if (visited[b])
			{
				cout << b << "\n";
				break;
			}
			b = parent[b];
		}
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}