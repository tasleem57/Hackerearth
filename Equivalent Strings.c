#include <stdio.h>
#define MOD 1000000007
 
int min (int x,int y)
{
	return x<y?x:y;
}
 
long long dp[2001][2001],sum[2001][2001];
int main()
{
    long long t,ans;
    int i,j,n,m;
    dp[0][0] = 1;
    
    for(i=1;i<2001;i++)
        for(j=1;j<=i;j++)
        {
            dp[i][j] = ((j*dp[i-1][j])%MOD + dp[i-1][j-1])%MOD;
            sum[i][j] = (sum[i][j-1] + dp[i][j])%MOD;
        }
    
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        ans = sum[n][min(n,m)];
        printf("%lld\n",ans);
    }
}
