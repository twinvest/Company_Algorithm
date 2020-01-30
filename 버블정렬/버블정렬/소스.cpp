#include <cstdio> 
#define MAX_SIZE 1000 
#define MAX_NUM 10000 
int main()
{
	int N, A[MAX_SIZE + 1], B[MAX_SIZE + 1], count[MAX_NUM + 1], countSum[MAX_NUM + 1];
	//수열의 길이 N은 MAX_SIZE이하여야합니다. 
	scanf("%d", &N);
	//count배열을 모두 0으로 초기화 
	for (int i = 0; i <= N; i++)
		count[i] = 0; //수열 A에 입력되는 수는 MAX_NUM 이하여야합니다. 
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]); //숫자 등장 횟수 세기 count[A[i]]++; } 
							//누적합 구성 
		countSum[0] = count[0];
		for (int i = 1; i <= MAX_NUM; i++)
			countSum[i] = countSum[i - 1] + count[i]; //뒤에서 부터 수열 A 순회한다.
		for (int i = N; i >= 1; i--)
		{
			B[countSum[A[i]]] = A[i];
			countSum[A[i]]--;
		}
		//수열 A를 정렬한 결과인 수열 B를 출력한다. 
		for (int i = 1; i <= N; i++)
			printf("%d ", B[i]);
	}
}