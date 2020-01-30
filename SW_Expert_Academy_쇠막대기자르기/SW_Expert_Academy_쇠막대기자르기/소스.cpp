#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string a) {
	int answer = 0;
	stack<char> s;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(')
			s.push(a[i]);
		else {
			s.pop();
			if (a[i - 1] == '(')
				answer += s.size();
			else
				answer++;
		}
	}
	return answer;
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
		printf("#%d %d\n", t, ans);
	}
}