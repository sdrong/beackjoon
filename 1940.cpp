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

bool visited[15001];
int arr[15001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long m;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 0; i < n-1; i++)
	{
		int now = arr[i];
		visited[i] = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (now + arr[j] == m && !visited[j])
			{
				visited[j] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}