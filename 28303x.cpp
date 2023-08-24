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

long arr[500001];
long dp[500001];
long bdp[500001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long k, n;
	cin >> n >> k;
	for (long i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (long i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1], (arr[i] - dp[i - 1]) * k);
		bdp[i] = max(dp[i - 1], (arr[n - i] - bdp[i - 1]) * k);
	}

	return 0;
}