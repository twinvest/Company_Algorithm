#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first > b.first;
}

int main()
{
	int K=0, N, testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int arr[20][20];
		vector<pair<int, pair<int, int>>> v;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int tmp;
				scanf("%d", &tmp);
				arr[i][j] = tmp;
				v.push_back(make_pair(tmp, make_pair(i, j)));
			}
		}
		sort(v.begin(), v.end(), compare);
		
		for (int i = 0; i < v.size(); ++i)
		{
			printf("%d, ÁÂÇ¥ : %d %d\n", v[i].first, v[i].second.first, v[i].second.second);
		}


	}

}