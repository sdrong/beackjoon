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

int t;

int arr[10001];

int sum[10001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[j];
			sum[i] = sum[j - 1] + arr[j];
		}
		for(int )
	}
	return 0;
}