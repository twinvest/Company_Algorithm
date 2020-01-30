#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
bool is_babyGin(vector<int> v)
{
	do
	{
		vector<int> tmp;
		for (int i = 0; i < v.size(); ++i)
			tmp.push_back(v[i]);
		for (int i = 0; i < v.size()/2; ++i)
		{

		}

	} while (next_permutation(v.begin(), v.end()));



	return true;
}

int main()
{
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	bool flag = is_babyGin(v);
	printf("%d", flag);
}