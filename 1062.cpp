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

int word, k;
string s[51];
bool alpha[27];

int big = 0;

void result()
{
	int cnt = 0;
	for (int i = 0; i < word; i++)
	{
		bool b = 1;
		for (int j = 0; j < s[i].length(); j++)
		{
			char now = s[i][j];
			if (!alpha[now - 'a'])
			{
				b = 0;
				break;
			}
		}
		if (b)
			cnt++;
	}
	big = max(big, cnt);
}

void soult(int n, int start)
{
	if (n == k)
	{
		result();
		return;
	}
	if (start >= 26)
		return;
	for (int i = start; i < 26; i++)
	{
		if (!alpha[i])
		{
			alpha[i] = 1;
			soult(n + 1, i);
			alpha[i] = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> word >> k;
	for (int i = 0; i < word; i++)
	{
		cin >> s[i];
	}
	if (k > 25)
	{
		cout << word;
		return 0;
	}
	if (k < 5)
	{
		cout << 0;
		return 0;
	}
	alpha['a' - 'a'] = 1;
	alpha['c' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	alpha['i' - 'a'] = 1;
	k -= 5;
	soult(0, 0);

	cout << big;
	return 0;
}