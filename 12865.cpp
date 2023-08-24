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

int n, w;
int weight[101];
int value[101];
int dp[101][100001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> w;
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i] >> value[i];
	}

	for (int now_w = 1; now_w <= w; now_w++)
	{
		for (int now_n = 1; now_n <= n; now_n++)
		{
			if (weight[now_n] > now_w) {
				dp[now_n][now_w] = dp[now_n - 1][now_w];
			}
			else {
				dp[now_n][now_w] = max(value[now_n] + dp[now_n-1][now_w-weight[now_n]], dp[now_n - 1][now_w]);
			}
		}
	}
	cout << dp[n][w];

	return 0;
}