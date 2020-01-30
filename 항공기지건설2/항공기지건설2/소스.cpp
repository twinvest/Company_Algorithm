#include<iostream>
#include<algorithm>
#pragma warning (disable : 4996)
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;
	int answer = 0;
	for (int t = 1; t <= testcase; ++t)
	{
		int arr[20][20];
		int N, K;
		cin >> N;
		cin >> K;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				int tmp = 0;
				for (int m = r; m < N; ++m)
				{
					for (int n = c; n < N; ++n)
					{
						int maximum = 0, minimal = 987654321;
						for (int a = r; a <= m; a++)
						{
							for (int b = c; b <= n; ++b)
							{
								maximum = max(maximum, arr[a][b]);
								minimal = min(minimal, arr[a][b]);
							}
						}
						if (abs(maximum) - abs(minimal) <= K)
						{
							tmp = max(tmp, abs(m - r + 1)*abs(n - c + 1));
						}
					}
				}
				answer = max(tmp, answer);
			}
		}
		printf("%d\n", answer);
	}
}