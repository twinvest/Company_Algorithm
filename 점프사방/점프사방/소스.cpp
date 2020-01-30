#include<iostream>
#include<vector>
#include<string>
#pragma warning (disable : 4996)
using namespace std;
int Y, X;

bool inside(int y, int x)
{
	return (y >= 0 && y < Y) && (x >= 0 && x < X);
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		vector<pair<pair<int, int>, int>> v;
		int arr[20][20];
		int participation, fall;

		cin >> Y>>X>> participation;
		
		for (int i = 0; i < Y; ++i)
			for (int j = 0; j < X; ++j)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < participation; ++i)
		{
			int y, x, jump;
			cin >> y >> x >> jump;
			--y; --x;
			v.push_back(make_pair(make_pair(y, x), jump));
		}

		cin >> fall;
		for (int i = 0; i < fall; ++i)
		{
			int y, x;
			cin >> y >> x;
			--y; --x;
			arr[y][x] = -1;
		}
		int sum = 0;
		//참가인원만큼
		for (int i = 0; i < v.size(); ++i)
		{
			//점프횟수
			for (int j = 0; j < v[i].second; ++j)
			{
				string tmp = to_string(arr[v[i].first.first][v[i].first.second]);
				if (tmp[0] == '1')
				{
					int num = tmp[1] - 48;
					if (!inside(v[i].first.first, v[i].first.second + num))
					{
						v[i].first.first = -1;
						v[i].first.second = -1;
						break;
					}
					v[i].first.second += num;
				}
				else if (tmp[0] == '2')
				{
					int num = tmp[1] - 48;
					if (!inside(v[i].first.first + num, v[i].first.second))
					{
						v[i].first.first = -1;
						v[i].first.second = -1;
						break;
					}
					v[i].first.first += num;
				}
				else if (tmp[0] == '3')
				{
					int num = tmp[1] - 48;
					if (!inside(v[i].first.first, v[i].first.second - num))
					{
						v[i].first.first = -1;
						v[i].first.second = -1;
						break;
					}
					v[i].first.second -= num;
				}
				else
				{
					int num = tmp[1] - 48;
					if (!inside(v[i].first.first - num, v[i].first.second))
					{
						v[i].first.first = -1;
						v[i].first.second = -1;
						break;
					}
					v[i].first.first -= num;
				}
			}
			if (arr[v[i].first.first][v[i].first.second] == -1)
			{
				v[i].first.first = -1;
				v[i].first.second = -1;
			}
		}

		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].first.first == -1 && v[i].first.first == -1)
				continue;
			sum += (arr[v[i].first.first][v[i].first.second] * 100);
		}

		printf("%d\n", sum - (participation*1000));
	}
}