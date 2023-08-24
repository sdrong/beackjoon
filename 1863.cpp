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

vector<int> v;

int total;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (y == 0)
		{
			while (!v.empty())
			{
				v.pop_back();
				total++;
			}
		}
		else if (v.empty())
		{
			v.push_back(y);
		}
		else if (v.back() < y)
			v.push_back(y);
		else
		{
			while (v.back() > y)
			{
				v.pop_back();
				total++;
				if (v.empty())
				{
					v.push_back(y);
					break;
				}
			}
			if (v.empty())
				continue;
			if (v.back() == y)
				continue;
			else if(v.back() < y)
				v.push_back(y);

		}
	}
	while (!v.empty())
	{
		v.pop_back();
		total++;
	}
	cout << total;
	return 0;
}