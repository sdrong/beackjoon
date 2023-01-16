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

char arr[9];

bool visited[10];

string big = "0";
string small = "9999999999";

bool check(string s)
{
	for (int i = 0; i < s.length()-1; i++)
	{
		if (arr[i] == '>')
		{
			if (!(s[i] > s[i + 1]))
				return false;
		}
		else if (arr[i] == '<')
		{
			if (!(s[i] < s[i + 1]))
				return false;
		}
	}
	return true;
}

void re(int cnt, string s)
{
	if (!check(s))
		return;
	if (cnt == n+1)
	{
		if (!check(s))
			return;
		if (small > s)
			small = s;
		if (big < s)
			big = s;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			re(cnt + 1, s+to_string(i));
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	re(0, "");
	cout << big << "\n" << small;
	return 0;
}