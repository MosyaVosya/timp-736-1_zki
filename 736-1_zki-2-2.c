#include <stdio.h>
int main()
{
	int n,i;
	double kvadrat=0,p=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&kvadrat);
		kvadrat=kvadrat*kvadrat;
		p=p+kvadrat;
	}
	printf("%f\n",p);
	return 0;
}
	
