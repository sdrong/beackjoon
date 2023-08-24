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

typedef struct fish {
	int number;
	int direction;
}fish;

fish arrs[4][4];

typedef struct pos {
	int x;
	int y;
}pos;

pos ps[16];

int big = 0;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void print(fish arr[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j].number << " " << arr[i][j].direction << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void re(fish arr[][4], int x, int y, int di, int point, pos p[16])
{
	if (x < 0 || x>3 || y < 0 || y > 3 || arr[y][x].number == 0 || di == 0)
	{
		big = max(big, point);
		return;
	}
	pos cp[16];
	for (int i = 0; i < 16; i++)
	{
		cp[i] = p[i];
	}
	fish carr[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			carr[i][j] = arr[i][j];
		}
	}
	point += arr[y][x].number;
	di = arr[y][x].direction;
	arr[y][x] = { 0 ,0 };
	for (int i = 0; i < 16; i++) // »ý¼± µé
	{
		if (arr[p[i].y][p[i].x].number != 0) 
		{
			int fx, fy;
			while (1) {
				fx = p[i].x + dx[arr[p[i].y][p[i].x].direction];
				fy = p[i].y + dy[arr[p[i].y][p[i].x].direction];
				if (fx < 0 || fx > 3 || fy < 0 || fy > 3)
				{

					arr[p[i].y][p[i].x].direction += 1;
					if (arr[p[i].y][p[i].x].direction + 1 > 8)
						arr[p[i].y][p[i].x].direction = 1;
				}
				else if (fx == x && fy == y)
				{
					arr[p[i].y][p[i].x].direction += 1;
					if (arr[p[i].y][p[i].x].direction + 1 > 8)
						arr[p[i].y][p[i].x].direction = 1;
				}
				else
					break;
			}

			int px1 = p[i].x;
			int py1 = p[i].y;

			int px2 = p[arr[fy][fx].number - 1].x;
			int py2 = p[arr[fy][fx].number - 1].y;

			pos pp = p[i];
			p[i] = p[arr[fy][fx].number - 1];
			p[arr[fy][fx].number - 1] = pp;
			
			fish temp = arr[py1][px1];
			arr[py1][px1] = arr[fy][fx];
			arr[fy][fx] = temp;
		}
	}
	int fx, fy;
	fx = x;
	fy = y;
	for(int i = 0 ; i < 3; i++)
	{
		fx += dx[di];
		fy += dy[di];
		re(arr, fx, fy, di, point, p);
		for (int i = 0; i < 16; i++)
		{
			p[i] = cp[i];
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arr[i][j] = carr[i][j];
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arrs[i][j].number >> arrs[i][j].direction;
			ps[arrs[i][j].number - 1].x = j;
			ps[arrs[i][j].number - 1].y = i;
		}
	}
	re(arrs, 0, 0, 1, 0, ps);
	
	cout << big;
	return 0;
}