#include<iostream>
#include<queue>
#pragma warning (disable : 4996)
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		queue<int> q1;
		queue<int> q2;
		queue<int> q3;

		int parking[101] = { 0, };
		int price[101];
		int car[2001];

		int parksize, numOfcar, sum = 0;
		cin >> parksize;
		cin >> numOfcar;

		for (int i = 1; i <= parksize; ++i)
		{
			scanf("%d", &price[i]);
		}

		for (int i = 1; i <= numOfcar; ++i)
		{
			scanf("%d", &car[i]);
		}

		for (int i = 1; i <= 2 * numOfcar; ++i)
		{
			int carnum;
			scanf("%d", &carnum);
			if(carnum>0)	q1.push(carnum);
			if (carnum<0)	q2.push(carnum);
			q3.push(carnum);
		}


		while (!q2.empty())
		{
			int cur = q3.front();
			bool flag = true;
			if (cur > 0)
			{
				for (int j = 1; j <= parksize; ++j)
				{
					if (j == parksize && parking[j] != 0)
					{
						flag = false;
						break;
					}

					if (parking[j] == 0 && flag) //parking[j]가 비어있으면서 주차를 할 수 있을때
					{
						parking[j] = cur;
						q3.pop();
						q1.pop();
						break;
					}
				}
			}
			if(cur < 0 || !flag)
			{
				int cur = q2.front();
				for (int j = 1; j <= parksize; ++j)
				{
					if (parking[j] == abs(cur))
					{
						parking[j] = 0;
						flag = true;
						if (cur < 0)
						{
							q2.pop();
							if(!flag)
								q3.pop();
						}
						sum = sum + (car[abs(cur)] * price[j]);
						break;
					}
						
				}
			}

		}
		printf("#%d %d\n",t, sum);
	}
}