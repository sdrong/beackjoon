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

int man;
int n;
int st;
int ed;
queue<int> q;
vector<int> v[101];

bool visited[101];
int dir[101];

void DFS()
{
	while (!q.empty())
	{
		int val = q.front();
		q.pop();
		visited[val] = 1;
		
		for (int i = 0; i < v[val].size(); i++)
		{
			if (!visited[v[val][i]])
			{
				q.push(v[val][i]);
				visited[v[val][i]] = 1;
				dir[v[val][i]] = dir[val] + 1;
			}
		}
	}
	
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> man;
	cin >> st >> ed;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;  
		v[s].push_back(e);
		v[e].push_back(s);
	}
	memset(dir, -1, sizeof(dir));
	visited[st] = 1;
	q.push(st);
	dir[st] = 0;
	DFS();
	cout << dir[ed];
	return 0;
}