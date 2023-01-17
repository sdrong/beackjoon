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
int arr[10][10];
int n;
int endflag = 0;

bool check(int r, int c, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][c] == num)
			return false;
		if (arr[r][i] == num)
			return false;
	}
	int row = r / 3 * 3;
	int col = c / 3 * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[row + i][col + j] == num)
				return false;
		}
	}
	return true;
}

void re(int r, int c)
{
	if (endflag == 1)
		return;
	if (r == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
			endflag = 1;
		}
	}
	if (c == 9)
	{
		re(r + 1, 0);
		return;
	}
	if (arr[r][c] == 0)
	{

		for (int i = 1; i <= 9; i++)
		{
			if (check(r, c, i))
			{
				arr[r][c] = i;
				re(r, c + 1);
				arr[r][c] = 0;
			}
		}
	}
	else
	{
		re(r, c + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
		}
	}
	re(0, 0);
	return 0;
}