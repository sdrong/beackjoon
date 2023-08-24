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

int n, n2;

void re(int sum, int num, int cnt, int sign, string s)
{
	if (cnt == n2)
	{
		sum += num * sign;
		if (sum == 0)
		{
			cout << s << "\n";
		}
	}
	re(sum, num*10 + (cnt+1), cnt+1, sign, s + ' ' + char(cnt + 1 + '0'));
	re(sum + sign * num, cnt + 1, cnt + 1, 1, s + '+' + char(cnt + 1 + '0'));
	re(sum + sign * num, cnt + 1, cnt + 1, -1, s + '-' + char(cnt + 1 + '0'));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		n2;
		cin >> n2;
		re(0, 1, 1, 1, "");
		cout << "\n";
	}
	return 0;
}