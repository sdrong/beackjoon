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

int n, m;
int start, goal;

vector<pair<int, int>> v[1001];
int dist[1001];
bool visited[1001];

void result(int r)
{
	dist[r] = 0;
	
	priority_queue<pair<int, int>>pq;
	pq.push({ r, dist[r] });

	while (!pq.empty()) {
		int now_node = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (dist[now_node] < distance)
			continue;
		
		for (int i = 0; i < v[now_node].size(); i++)
		{
			int new_node = v[now_node][i].first;
			int new_distance = distance + v[now_node][i].second;

			if (new_distance < dist[new_node])
			{
				dist[new_node] = new_distance;
				pq.push({ new_node, new_distance });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dist[i] = 987654321;
	for (int i = 0; i < m; i++)
	{
		int s, e, val;
		cin >> s >> e >> val;
		v[s].push_back(make_pair(e, val));
	}
	cin >> start >> goal;
	result(start);
	cout << dist[goal];
	return 0;
}