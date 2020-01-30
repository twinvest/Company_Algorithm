#include <cstdio>
#include <iostream>
#include <string>
#pragma warning (disable : 4996)
using namespace std;
int dfs(string s1, string s2, int depth)
{
	string tmp;
	if (s1.size() == depth)
		return -1;

	if (s1 == s2)
		return depth;
	for (int i = 0; i < s1.size(); ++i)
	{
		if (i == 0)
		{
			if (s2[i] == '1') s2[i] = '0';
			else s2[i] = '1';
		}
		else if (i == s1.size() - 1)
		{
			if (s2[i] == '1') s2[i] = '0';
			else s2[i] = '1';
		}
		else if (i != 0 && i != s1.size() - 1)
		{
			if (s2[i - 1] == '1') s2[i - 1] = '0';
			else s2[i - 1] = '1';

			if (s2[i] == '1') s2[i] = '0';
			else s2[i] = '1';

			if (s2[i + 1] == '1') s2[i + 1] = '0';
			else s2[i + 1] = '1';
		}
		dfs(s1, s2, depth + 1);
	}
}


int main()
{
	int arr[100000];
	int num;
	scanf("%d", &num);

	string s1, s2;
	cin >> s1;
	cin >> s2;
	int ans = dfs(s1, s2, 1);
	printf("%d", ans);
}