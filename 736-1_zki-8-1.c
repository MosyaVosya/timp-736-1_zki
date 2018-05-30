#include <stdio.h>
#include <stdlib.h>
void QuickSort(int k, int l, int mass[])
{
	double temp;
	int i = k;
	int j = l;
	int x = mass[(k + l) / 2];
	while (i <= j)
	{
		while (mass[i] < x)
			i++;
		while (mass[j] > x)
			j--;
		if (i <= j)
		{
			if (i < j)
			{
				temp = mass[i];
				mass[i] = mass[j];
					mass[j] = temp;
			}
			i++;
			j--;
		}
	}
	if (i < l)  
		QuickSort(i, l, mass);
	if (k < j)  
	{
		QuickSort(k, j, mass);
	}
}
int main()
{
	int n;
	int* m;
	scanf("%d", &n);
	m = (int *)malloc(n * sizeof(int));
	
		for (int i = 0; i < n; i++)
		{
			scanf("%d ",&m[i]);
		}
		QuickSort(0, n - 1, m);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", m[i]);

	}
	 printf("\n");

	free(m);
	return 0;
}
