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
int n2;

vector<int> v;

int arr2[9];

bool visited[9];

void re(int cnt)
{
	if (cnt == n2 + 1)
	{
		for (int i = 1; i <= n2; i++)
		{
			cout << arr2[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		arr2[cnt] = v[i];
		re(cnt + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> n2;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	re(1);
	return 0;
}