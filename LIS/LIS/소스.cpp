#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	int dp[1000];
	int arr[1000];
	int testcase;
	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; ++t)
	{
		int ans = 0;
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		
		int N;
		scanf("%d", &N);
		//ÀÔ·ÂºÎ
		for (int i = 0; i < N; ++i)
			scanf("%d", &arr[i]);

		
		for (int i = 0; i < N; ++i)
		{
			if (dp[i] == 0) dp[i] = 1;

			for (int j = 0; j < i; ++j)
			{
				if (arr[i] > arr[j])
				{
					if (dp[i] < dp[j] + 1)
					{
						dp[i] = dp[j] + 1;
						ans = max(ans, dp[i]);
					}
				}
			}
		}
		printf("#%d %d\n", t, ans);
	}
}