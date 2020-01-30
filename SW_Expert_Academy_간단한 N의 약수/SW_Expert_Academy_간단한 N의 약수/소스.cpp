#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int i = 1;
	vector<int> v;
	while (i <= num)
	{
		if (num % i == 0)
			v.push_back(i);
		++i;
	}
	sort(v.begin(), v.end());
	for (int j = 0; j < v.size(); ++j)
		printf("%d ", v[j]);
}