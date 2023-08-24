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

vector<pair<int, int>> v;
bool visited[11];
int small = 999999999;

void Get_Result(int num, int data1, int data2)
{
	int r = data1 - data2;
	small = min(small, abs(r));
	for (int i = num + 1; i < n; i++)
	{
		Get_Result(i, data1 * v[i].first, data2 + v[i].second);
		Get_Result(i ,data1, data2);
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
		int data1, data2;
		cin >> data1 >> data2;
		v.push_back(make_pair(data1, data2));
	}

	for (int i = 0; i < n; i++)
	{
		Get_Result(i, v[i].first, v[i].second);
	}

	cout << small;

	return 0;
}