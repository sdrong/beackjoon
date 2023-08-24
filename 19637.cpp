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
long long c, n;
long long arr[100001];
string st[100001];

string re(int num)
{
	int mid = 0, head = 0, tail = c - 1;
	while (head <= tail)
	{
		mid = (head + tail) / 2;
		if (num <= arr[mid])
		{
			tail = mid - 1;
		}
		else
			head = mid + 1;
	}
	if (num > arr[mid])
		return st[mid + 1];
	else
		return st[mid];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n;
	for (int i = 0; i < c; i++)
	{
		cin >> st[i] >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		cout << re(num) << "\n";
	}
	return 0;
}