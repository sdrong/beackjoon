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
int m;
int arr[51][51];
int max_size;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	max_size = min(n, m);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	int b = 0;
	while (max_size > 1 && b == 0)
	{
		for (int i = 0; i <= n-max_size; i++)
		{
			for (int j = 0; j <= m-max_size; j++)
			{
				int cp = arr[i][j];
				if (arr[i + max_size-1][j] == cp && arr[i][j + max_size-1] == cp && arr[i + max_size-1][j + max_size-1] == cp)
				{
					b = 1;
					break;
				}
			}
			if (b == 1)
				break;
		}
		if (b == 1)
			break;
		max_size--;
	}
	cout << max_size * max_size;

	return 0;
}