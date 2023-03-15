#include <stdio.h>
#include<limits.h>
#define MAX 1000
int main(){
	int a[MAX],p,q,n,cost[MAX],j,k=0,totalCost=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++)
	{
		p=a[0],q=a[i+1];
		
		//for(n--,j=q;j<n;j++){a[j]=a[j+1];j--;}
		cost[k++]=((p+q)+(p|q)-(p&q));
	}
   for(int i=0;i<k;i++)
   {
	   totalCost=(totalCost|cost[i]);
   }
  printf("%d",totalCost);
}
