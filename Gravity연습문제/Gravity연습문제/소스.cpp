#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable : 4996)
using namespace std;
int A[10][10] = { 0, };
int B[10][10];
int height[10];
vector<int> v;
bool flag;
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		scanf("%d", &height[i]);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < height[i]; ++j)
			A[i][j] = 1;
	/*
	printf("\n\n");
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	*/
	for (int i = 0; i < N; ++i)
	{
		flag = false;
		int count = 0;
		for (int j = 0; j < N; ++j)
		{
			if (A[j][i] == 0 && flag == true)
				count++;
			if (A[j][i] == 1)
				flag = true;
		}
		if (count == N) continue;
		v.push_back(count);
	}

	//for (int i = 0; i < v.size(); ++i)
	//	printf("%d ", v[i]);

	sort(v.begin(), v.end());
	printf("%d", v[v.size() - 1]);

}