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
vector<int> v;
int re[1000001];

void get_re(int num, int next_num)
{
	if (next_num >= n)
	{
		re[num] = n;
		return;
	}
	if (v[num] < v[next_num])
		re[num] = next_num;
	else if (v[num] < v[re[next_num]])
	{
		re[num] = re[next_num];
	}
	else
	{
		get_re(num, re[next_num]);
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
		int num;
		cin >> num;
		v.push_back(num);
	}
	v.push_back(-1);
	for (int i = n - 1; i >= 0; i--)
	{
		get_re(i, i+1);
	}
	for (int i = 0; i < n; i++)
	{
		cout << v[re[i]] << " ";
	}
	return 0;
}