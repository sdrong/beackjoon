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
int temp[9];
bool visited[9];

void re(int cnt, int start)
{
	if (cnt == n2)
	{
		for (int i = 0; i < n2; i++)
		{
			cout << arr2[i] << " ";
		}
		cout << "\n";
		return;
	}
	int pre = -1;
	for (int i = start; i < v.size(); i++)
	{
		if (!visited[i] && pre != v[i])
		{
			visited[i] = true;
			arr2[cnt] = v[i];
			pre = v[i];
			re(cnt + 1, i);
			visited[i] = false;
		}
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
	re(0, 0);
	return 0;
}