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

bool visited[1001];
int re;
int n;

typedef struct t {
	char c;
	int m;
	vector<int>ve;
}t;

vector<t> v;

void dfs(int here, int coin)
{
	if (re == 1)
		return;
	if (here == n)
	{
		re = 1;
		return;
	}
	for (int i = 0; i < v[here].ve.size(); i++)
	{
		int next = v[here].ve[i];
		if (!visited[next])
		{
			if (v[next].c == 'L')
			{
				if (coin < v[next].m)
					coin = v[next].m;
			}
			else if (v[next].c == 'T')
			{
				coin -= v[next].m;
			}
			if (coin < 0)
				return;
			visited[next] = 1;
			dfs(next, coin);
			visited[next] = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		re = 0;
		cin >> n;
		if (n == 0)
			break;
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			char cn;
			cin >> cn;
			v[i].c = cn;  // 방의 형태 데이터 삽입
			int put_num;
			cin >> put_num;
			v[i].m = put_num;  //방의 금액 삽입
			while (1) {
				cin >> put_num;
				if (put_num == 0)
					break;
				v[i].ve.push_back(put_num);  // 이어지는 방 삽입
			}
		}

		if (v[1].c == 'E')
		{
			visited[1] = 1;
			dfs(1, 0);
		}
		else if (v[1].c == 'L')
		{
			visited[1] = 1;
			dfs(1, v[1].m);
		}
		else if (v[1].c == 'T')
		{
			re = 0;
		}

		if (re == 1)
		{
			cout << "Yes\n";
		}
		else
			cout << "No\n";

		v.clear();
		for (int i = 0; i <= n; i++)
		{
			visited[i] = 0;
		}
	}

	return 0;
}