#include <cstdio>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
#define W 0
#define V 1
#define N 5
#define MAX(a,b) a>b ? a:b;


int items[5][2] = {
{200,100},
{500,300},
{300,250},
{1000,500},
{400,400}
};

int knapsack(int pos, int capacity) {
	if (pos == N) return 0;

	int ret = 0;
	if (items[pos][W] <= capacity) //지금 pos의 물건을 훔칠 수 있을때
		ret = knapsack(pos + 1, capacity - items[pos][W]) + items[pos][V];
	//지금 pos의 물건을 훔치지 않을때와 ret 중에 큰 값
	ret = MAX(ret, knapsack(pos + 1, capacity));
	return ret;
}

int main()
{
	//int ans;
	int testcase;
	scanf("%d", &testcase);
	int capacity = 1000;		
	printf("knapsack(%d,%d)=%d\n", 0, capacity, knapsack(0, capacity));

}