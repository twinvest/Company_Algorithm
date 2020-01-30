#include<iostream>
using namespace std;
int sum(int num)
{
	if (num == 1)
		return 1;
	return num + sum(num - 1);
}
int main()
{
	int num;
	cin >> num;
	printf("%d", sum(num));
}