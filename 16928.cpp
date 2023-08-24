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

int p, m;

int arr[101];
int dir[101];
bool visited[101];
map<int, int> pp, mm;

void BFS(int num)
{
	queue<int> q;
	q.push(num);
	visited[num] = 1;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		
		for (int i = 1; i <= 6; i++)
		{
			if (here + i < 101 && !visited[here + i])
			{
				if (pp.find(here+i) != pp.end())
				{
					if (!visited[pp[here+i]])
					{
						q.push(pp[here + i]);
						visited[pp[here + i]] = 1;
						dir[pp[here + i]] = dir[here]+1;
					}
				}
				else if (mm.find(here + i) != mm.end())
				{
					if (!visited[mm[here + i]])
					{
						q.push(mm[here + i]);
						visited[mm[here + i]] = 1;
						dir[mm[here + i]] = dir[here] + 1;
					}
				}
				else {
					q.push(here + i);
					visited[here + i] = 1;
					dir[here + i] = dir[here] + 1;
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> p >> m;
	for (int i = 0; i < p; i++)
	{
		int s, e;
		cin >> s >> e;
		pp.insert({ s, e });
	}
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		mm.insert({ s, e });
	}
	BFS(1);
	cout << dir[100];
	return 0;
}