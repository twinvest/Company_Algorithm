#include<iostream>
#include<algorithm>
#include<string>
#pragma warning(disable : 4996)
using namespace std;
int main()
{
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; ++t)
	{
		string s;
		cin >> s;
		char cur = '0';
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (cur != s[i])
			{
				++count;
				cur = s[i];
			}
		}
		printf("#%d %d\n", t, count);
	}
}