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

int big = 0;

void re(vector<int> ve, int num, int sum)
{
	if (ve.size() == 2)
	{
		big = max(big, sum);
		return;
	}
	for (int i = 1; i < ve.size() - 1; i++)
	{
		int val = ve[i];
		sum += ve[i - 1] * ve[i + 1];
		ve.erase(ve.begin() + i);
		re(ve, i, sum);
		ve.insert(ve.begin() + i, val);
		sum -= ve[i - 1] * ve[i + 1];
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
	for(int i = 1; i < n - 1; i++)
		re(v, i, 0);
	cout << big;
	return 0;
}