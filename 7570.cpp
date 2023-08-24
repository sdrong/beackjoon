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
int dp[1000001];
int re;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		dp[num] = dp[num - 1] + 1;
		re = max(re, dp[num - 1] + 1);
	}
	cout << n - re;
	return 0;
}