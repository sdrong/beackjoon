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

int test_count;
int n;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> test_count;
	for (int i = 0; i < test_count; i++)
	{
		map<string, int> m;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			string s;
			string name;
			cin >> name >> s;
			if (m.find(s) == m.end())
			{
				m.insert({ s, 1 });
			}
			else
			{
				m[s]++;
			}
		}
		int re = 1;
		for (auto j : m)
		{
			re *= (j.second+1);
		}
		cout << re - 1 << "\n";
	}
	return 0;
}