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

int man_num;
int party_num;

int knows[51];

vector<int> know;
vector<vector<int>> party;

int find(int a)
{
	if (knows[a] == a)
		return a;
	else
		return find(knows[a]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	knows[b] = a;
}

bool isUnion(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return true;
	else
		return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int re;
	cin >> man_num >> party_num;
	re = party_num;
	party.resize(party_num + 1);
	for (int i = 1; i <= man_num; i++)
	{
		knows[i] = i;
	}
	int know_num;
	cin >> know_num;
	for (int i = 0; i < know_num; i++)
	{
		int n;
		cin >> n;
		know.push_back(n);
		knows[n] = 0;
	}
	for (int i = 0; i < party_num; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			party[i].push_back(num);
		}
	}

	for (int i = 0; i < party_num; i++)
	{
		int a = party[i][0];
		for (int j = 1; j < party[i].size(); j++)
		{
			int b = party[i][j];
			Union(a, b);
		}
	}

	for (int i = 0; i < party_num; i++)
	{
		bool check = true;
		for (int j = 0; j < party[i].size(); j++)
		{
			if (!check)
				break;
			int a = party[i][j];
			for (int k = 0; k < know.size(); k++)
			{
				int b = know[k];
				if (isUnion(a, b))
				{
					check = false;
					break;
				}
			}
		}
		if (!check)
			re--;
	}
	cout << re;

	return 0;
}