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
int arr[2000];
bool visited[2000];
vector<int> v[101];

void DFS(int num)
{
	for (int i = 0; i < v[num].size(); i++)
	{
		int val = v[num][i];
		if (!visited[val])
		{
			visited[val] = 1;
			DFS(val);
		}

	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if (a)
			{
				v[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		DFS(i);
		for (int j = 1; j <= n; j++)
		{
			cout << visited[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}