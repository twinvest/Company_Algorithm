#include<cstdio>

int main()
{
	int arr[] = { 5,8,1,4,7,3,2,9,6 };
	for (int i = 0; i < sizeof(arr)/4; ++i)
	{
		for (int j = i; j < sizeof(arr) / 4; ++j)
		{
			int tmp=987654321;
			if (tmp > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}