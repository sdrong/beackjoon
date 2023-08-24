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
long long dp[10000010];

int n;

void result()
{
	queue<long long> q;
	for (int i = 1; i <= 9; i++)
	{
		q.push(i);
		dp[i] = i;
	}
	if (n >= 0 && n <= 10)
	{
		cout << n;
		return;
	}
	int i = 10;
	while (!q.empty() && i <= n)
	{
		long long num = q.front();
		q.pop();
		int one = num % 10;
		for(int j = 0 ; j < one; j++)
		{
			int r = num * 10 + j;
			q.push(r);
			dp[i++] = r;
		}
	}
	if (i >= n && dp[n])
		cout << dp[n];
	else
		cout << -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	result();
	return 0;
}