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

long long dp[31][31];

int n;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n = 1;
	for (int i = 0; i < 31; i++)
	{
		dp[0][i] = 1;
	}
	
	for (int i = 1; i < 31; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][1]; // 약 반개가 없으므로 무조건 한개짜리 약을 써야 하므로
			else
				dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1]; // 약 한개를 썻을 때 + 약 반개를 썻을 때
		}
	}
	while (n) {
		cin >> n;
		if (!n)
			break;
		cout << dp[n - 1][1] << "\n";
	}


	return 0;
}