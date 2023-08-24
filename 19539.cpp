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

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	int sum = 0;
	int two = 0;
	int three = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		sum += num;
		two += num / 2;
	}
	if (sum % 3 != 0)
		cout << "NO";
	else {
		three = sum / 3;
		if (two < three)
			cout << "NO";
		else
			cout << "YES";
	}
	return 0;
}