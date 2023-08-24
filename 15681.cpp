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
int r;
int num;

vector<int> ve[100001];
bool visited[100001];
int result[100001];

int DFS(int u)
{
	if (result[u] != 0)
		return result[u];
	visited[u] = 1;
	int cnt = 1;
	for (int i = 0; i < ve[u].size(); i++)
	{
		if (!visited[ve[u][i]])
		{
			cnt += DFS(ve[u][i]);
		}
	}
	result[u] = cnt;
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> num >> r;
	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		ve[s].push_back(e);
		ve[e].push_back(s);
	}
	result[num] = DFS(num);
	for (int i = 0; i < r; i++)
	{
		int user;
		cin >> user;
		cout << result[user] << "\n";
	}
	return 0;
}