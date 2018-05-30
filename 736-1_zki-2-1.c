#include <stdio.h>
int main()
{
	int i,n;
	double k,mid=0,sum=0;
	scanf("%d",&n);
	for (i=1;i<n+1;i++)
	{
		scanf("%lf",&k);
		sum+=k;
		mid=sum/i;
	}
	printf("%lf\n",mid);
	return 0;
}
	
