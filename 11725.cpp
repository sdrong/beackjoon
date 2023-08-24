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

vector<int> v[100001];
int arr[100001];
bool visited[100001];

int n;

void DFS(int val)
{
	visited[val] = 1;
	for (int i = 0; i < v[val].size(); i++)
	{
		int data = v[val][i];
		if (!visited[data])
		{
			arr[data] = val;
			DFS(data);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int s, e;
	for (int i = 1; i < n; i++)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	DFS(1);
	for (int i = 2; i <= n; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}