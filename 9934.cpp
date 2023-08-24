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
int arr[2000];
bool visited[2000];
vector<int> v[10];

void print(int s, int e, int d)
{
	int mid = (s + e) / 2;
	v[d].push_back(arr[mid]);
	if (s >= e)
		return;
	print(s, mid-1, d+1);
	print(mid + 1, e, d+1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int sd = pow(2, n) - 1;
	for (int i = 0; i < sd; i++)
	{
		cin >> arr[i];
	}
	print(0, sd, 0);
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < v[k].size(); i++)
		{
			
			cout << v[k][i] << " ";
		}
		cout << "\n";
	}
	return 0;
}