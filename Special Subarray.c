#include<stdio.h>
#include<limits.h>
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, i, j, cnt=0;
		scanf("%d", &n);
		long int a[n], sum = 0, xr=0;
		for(i=1; i<=n; i=i+1)
		{
			scanf("%ld", &a[i]);
		}
 
		for(j=1; j<=n; j=j+1)
		{
			sum = 0, xr = 0;
			for(i=j; i<=n; i=i+1)
			{
				sum = sum + a[i];
				xr = xr ^ a[i];
				if((sum-xr)>0)
					break; 
				if(sum == xr)
				{
					cnt = cnt+1;
				}		
			}	
		}
		printf("%d\n", cnt);
	}
	return 0;
}
