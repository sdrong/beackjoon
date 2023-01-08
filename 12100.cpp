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

long long big;

vector<vector<long long>> left(vector<vector<long long>> arr)
{
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[i][j] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (arr[i][k] == arr[i][k + 1] && !visited[i][k])
				{
					arr[i][k] *= 2;
					arr[i][k + 1] = 0;
					visited[i][k] = 1;
					break;
				}
				else if (arr[i][k] == 0)
				{
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	
	return arr;
}

vector<vector<long long>> right(vector<vector<long long>> arr)
{
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = n-2; j >= 0; j--)
		{
			if (arr[i][j] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i][k] == arr[i][k - 1] && !visited[i][k])
				{
					arr[i][k] *= 2;
					arr[i][k - 1] = 0;
					visited[i][k] = 1;
					break;
				}
				else if (arr[i][k] == 0)
				{
					arr[i][k] = arr[i][k - 1];
					arr[i][k - 1] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	return arr;
}

vector<vector<long long>> up(vector<vector<long long>> arr)
{
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[j][i] == 0)
				continue;
			for (int k = j-1; k >= 0; k--)
			{
				if (arr[k][i] == arr[k+1][i] && !visited[k][i])
				{
					arr[k][i] *= 2;
					arr[k+1][i] = 0;
					visited[k][i] = 1;
					break;
				}
				else if (arr[k][i] == 0)
				{
					arr[k][i] = arr[k+1][i];
					arr[k+1][i] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	return arr;
}

vector<vector<long long>> down(vector<vector<long long>> arr)
{
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = n-2; j >= 0; j--)
		{
			if (arr[j][i] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (arr[k][i] == arr[k-1][i] && !visited[k][i])
				{
					arr[k][i] *= 2;
					arr[k - 1][i] = 0;
					visited[k][i] = 1;
					break;
				}
				else if (arr[k][i] == 0)
				{
					arr[k][i] = arr[k-1][i];
					arr[k-1][i] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	return arr;
}

void re(int cnt, vector<vector<long long>> arr)
{
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				big = max(big, arr[i][j]);
			}
		}
		return;
	}
	re(cnt + 1, left(arr));
	re(cnt + 1, right(arr));
	re(cnt + 1, up(arr));
	re(cnt + 1, down(arr));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<long long>> arr;
	cin >> n;
	arr.assign(n + 1, vector<long long>(n + 1, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			big = max(big, arr[i][j]);
		}
	}
	re(0, arr);
	cout << big;
	return 0;
}