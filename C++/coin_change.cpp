#include <iostream>
#include <cstring>

using namespace std;

int coins[5] = { 1, 5, 10, 25, 50 };
int memo[8000][10];


int recursive(int val, int n)
{

	if (val < 0 || n < 0)
		return 0;

	if (memo[val][n] != -1)
		return memo[val][n];

	if (val == 0)
	{
		memo[val][n] = 1;
		return memo[val][n];
	}

	memo[val][n] = recursive(val - coins[n], n) + recursive(val, n - 1);

	return memo[val][n];
}

int main()
{
	int val;
	memset(memo, -1, sizeof(memo));
	while (cin >> val)
	{
		cout << recursive(val, 4) << endl;
	}
	return 0;
}