#include<iostream>
#include<cstdlib>
int arr[3][3] = { 
	{1,2,3},
	{1,2,3},
	{1,2,3}
};

int dir[4][2] = { {-1, 0},{1, 0},{0, 1},{0,-1} };

bool inside(int i, int j) 
{ 
	return (i >= 0 && i < 3) && (j >= 0 && j < 3); 
}
int main()
{
	int sum = 0;
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			int cur = arr[y][x];
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];
				if (!inside(ny, nx)) continue;
				sum += abs(cur - arr[ny][nx]);
			}
		}
	}
	printf("%d", sum);
}