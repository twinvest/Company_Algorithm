#include <cstdio> 
#define MAX_SIZE 1000 
#define MAX_NUM 10000 
int main()
{
	int N, A[MAX_SIZE + 1], B[MAX_SIZE + 1], count[MAX_NUM + 1], countSum[MAX_NUM + 1];
	//������ ���� N�� MAX_SIZE���Ͽ����մϴ�. 
	scanf("%d", &N);
	//count�迭�� ��� 0���� �ʱ�ȭ 
	for (int i = 0; i <= N; i++)
		count[i] = 0; //���� A�� �ԷµǴ� ���� MAX_NUM ���Ͽ����մϴ�. 
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]); //���� ���� Ƚ�� ���� count[A[i]]++; } 
							//������ ���� 
		countSum[0] = count[0];
		for (int i = 1; i <= MAX_NUM; i++)
			countSum[i] = countSum[i - 1] + count[i]; //�ڿ��� ���� ���� A ��ȸ�Ѵ�.
		for (int i = N; i >= 1; i--)
		{
			B[countSum[A[i]]] = A[i];
			countSum[A[i]]--;
		}
		//���� A�� ������ ����� ���� B�� ����Ѵ�. 
		for (int i = 1; i <= N; i++)
			printf("%d ", B[i]);
	}
}