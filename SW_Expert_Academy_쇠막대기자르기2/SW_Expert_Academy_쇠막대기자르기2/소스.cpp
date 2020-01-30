#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(string arrangement) {
	int ans = 0;
	vector<int> v(arrangement.size(), 0);
	stack<char> s2;
	bool flag = false;
	int len = 0;

	char rem = ')';
	for (int i = 0; i < arrangement.length(); i++)
	{
		// '('�� ��� ==> ���ÿ� Ǫ��Ǫ��~~
		if (arrangement[i] == '(')
		{
			s2.push(arrangement[i]);
			//printf("%c", s2.top());
			rem = '(';
		}
		// ')'�� ���
		else
		{
			//printf("%c", arrangement[i]);
			//��������. �ֳı�? �ٷ� ���� ��ȣ�� ���ٲ� rem�� �����ѳ����ϱ�! �������� -1�� �ʱ�ȭ
			if (s2.top() == '(' && rem == '(')
			{
				s2.pop();
				v[i] = -1;
				v[i - 1] = -1;
				rem = ')';
			}
			//������� ����. ������� ���� ��ȣ�� ǥ���صд�.
			else if (s2.top() == '(')
			{
				v[i] = ++len;
				rem = ')';
			}
		}
	}

	//������� ù��ġ�� ã�ư��� �ݺ���
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[j] == i)
			{
				for (int k = j; ; --k)
				{
					if (v[k] == 0)
					{
						v[k] = i;
						break;
					}
				}
			}
		}
	}

	//���ܵ� ������� ������ ���� �ݺ���
	int count = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[j] == i) //������ġ
			{
				int k = j + 1;
				while (v[k] != i)
				{
					if (v[k] == -1) count++;
					++k;
				}
				count /= 2;
				ans = ans + 1 + count;
				count = 0;
				break;
			}
		}
	}
	/*
	printf("\n\n");
	for (int i = 0; i < v.size(); ++i)
	{
		printf("%d ", v[i]);
	}
	printf("\n\n");
	*/

	return ans;
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		string s;
		cin >> s;
		int ans = solution(s);
		printf("#%d %d\n",t, ans);
	}
}