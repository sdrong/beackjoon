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

int n, n2, s;
vector<int> graph[1000001];
int visited[1000001];
int result[1000001];
int cnt;

void DFS(int v)
{
	if (visited[v])
		return;
	visited[v] = true;
	cnt++;
	result[v] = cnt;
	for (int i = 0; i < graph[v].size(); i++)
	{
		DFS(graph[v][i]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> n2 >> s;
	for (int i = 0; i < n2; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	DFS(s);
	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";
	return 0;
}