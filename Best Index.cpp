#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
 
 
 
int main()
 
{
 
ios_base::sync_with_stdio(false);
 
cin.tie(NULL);
 
int n;
 
cin>>n;
 
ll A[100000];
 
for(int i = 0; i<n; i++)
 
cin>>A[i];
 
 
 
ll prefixSum[100001];
 
int terms[100000];
 
int term = 1;
 
int index = n-1;
 
while(index >= 0)
 
{
 
for(int i = 0; i<=term; i++)
 
terms[index--] = term;
 
term++;
 
}
 
prefixSum[0] = 0;
 
for(int i = 1; i<=n; i++)
 
prefixSum[i] = prefixSum[i-1] + A[i-1];
 
 
 
 
ll specialSum = -10000000;
 
 
 
 
for(int i = 0; i<n; i++)
 
{
 
int lastIndex = i + (terms[i] * (terms[i] +1))/2;
 
ll sum = prefixSum[lastIndex] - prefixSum[i];
 
specialSum = max(specialSum, sum);
 
}
 
 
 
 
cout<<specialSum<<endl;
 
}
