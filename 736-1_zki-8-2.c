#include <stdio.h>
#include <stdlib.h>
void HeapSort(int m[], int x, int down )
{
	int mP, temp, end = 0;
	while ((x * 2 <= down) && (!end))
	{
		if (x * 2 == down)
			mP = x * 2;
		else if (m[x * 2] > m[x * 2 + 1]) 
			mP = x * 2;
		else
			mP = x * 2 + 1; 
		if (m[x] < m[mP]) 
		{
			temp = m[x];
			m[x] = m[mP];
			m[mP] = temp;
			x = mP;
			 
		}
		else
 
		{
			end = 1;
		}
	}
}
void Heap(int m[], int size)
{
	for (int i = (size / 2) - 1; i >= 0; i--)
		HeapSort(m, i, size);
	for (int i = size - 1; i >= 1; i--)
	{
		int temp = m[0];
		m[0] = m[i];
		m[i] = temp;
		HeapSort(m, 0, i - 1);
	}
 
}
int main()
{
	int n, i; int* m;
	scanf("%d", &n);
	m = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d",&m[i]);
		
	}
	Heap(m, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", m[i]);
	}
	printf("\n");
	free(m);
	return 0;
}
