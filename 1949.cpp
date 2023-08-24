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

int dp[10001][2];
int val[10001];
bool visited[10001];
vector<int> v[10001];

int n;

void BFS(int ve)
{
	visited[ve] = 1;
	dp[ve][0] = 0;
	dp[ve][1] = val[ve];

	for (int i = 0; i < v[ve].size(); i++)
	{
		int a = v[ve][i];
		if (!visited[a])
		{
			BFS(a);
			dp[ve][0] += max(dp[a][0], dp[a][1]);
			dp[ve][1] += dp[a][0];
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
		cin >> val[i];
	}
	for (int i = 1; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	BFS(1);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}