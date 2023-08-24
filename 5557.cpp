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

long long dp[101][21];
int arr[101];

int n;

void DP_START()
{
	dp[0][arr[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j] == 0)
				continue;
			if (j + arr[i] <= 20)
			{
				dp[i][j + arr[i]] += dp[i - 1][j];
			}
			if (j - arr[i] >= 0)
			{
				dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	DP_START();
	
	cout << dp[n-2][arr[n-1]];
	return 0;
}