#include <stdio.h>
#include <stdlib.h>
void CombSort(int n, int m[])
{
	int i, j, s = n, tmp;
	while (n>1) {
		s /= 1.2473309;
				 
		if (s<1) 
		s = 1;  
		j = 0;  
		for (i = 0; i + s<n; i++) {  
			if ((m[i] / 10)>(m[i + s] / 10)) {
				tmp = m[i];
				m[i] = m[i + s];
				m[i + s] = tmp;
				j = i;
			}
			
		}
		if (s == 1) 
			n = j + 1;
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
	CombSort(N, m);
	for (int i = 0; i < N; i++)
		printf("%d ", m[i]);
	printf("\n");
	return 0;
}
