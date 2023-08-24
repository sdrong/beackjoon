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
int arr[201];
int dp[201];

int n;

int big;

void get_result()
{
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (dp[i] <= dp[j] && arr[i] > arr[j])
			{
				dp[i] = dp[j] + 1;
				big = max(dp[i], big);
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
	{
		cin >> arr[i];
	}
	get_result();
	cout << n - big;
	return 0;
}