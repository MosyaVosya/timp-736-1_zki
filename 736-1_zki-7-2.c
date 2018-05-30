#include <stdio.h>
#include <stdlib.h>
void ShellSort(int n, int m[])
{
	int i, j,s,tmp;
	for (s = n / 2; s > 0; s /= 2)
		for (i = s; i < n; i++)
		{
			tmp = m[i];
			for (j = i; j >= s; j -= s)
			{
				if (tmp < m[j - s])
					m[j] = m[j - s];
				else
					break;
			}
			m[j] = tmp;
		}
}

int main()
{
	int N;
	scanf("%d", &N);
	int* m;
	m = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		scanf("%d", &m[i]);
	ShellSort(N, m);
	for (int i = 0; i < N; i++)
		printf("%d ", m[i]);
	printf("\n");
	return 0;
}
