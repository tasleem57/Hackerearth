#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define int long long int
#define LLONG_MAX 98765435353
#define LLONG_MIN -1
#define MAXN 300005
#define SQRSIZE 548
 
int arr[MAXN]; // original array
int block[SQRSIZE]; // decomposed array
int blk_sz; // block size
 
// Time Complexity : O(1)
int min(int a, int b){
	return a < b ? a : b;
}
 
 
int max(int a, int b){
	return a > b ? a : b;
}
 
// Driver code
signed main()
{
	int n, q, i, j, l, r;
	int mini = LLONG_MAX;
	scanf("%lld %lld", &n, &q);
	int* ar = (int*)malloc(n * sizeof(int));
	int* vec = (int*)malloc(n * sizeof(int));
	int* minvec = (int*)malloc(n * sizeof(int));
	memset(ar, 0, sizeof(ar));
	memset(ar, 0, sizeof(vec));
	memset(ar, 0, sizeof(minvec));
	for(i = 0;i<n;i++){
		scanf("%lld", &ar[i]);
	}
	mini = LLONG_MAX;
	for(i = 0;i<n;i++){
		mini = min(mini, ar[i]);
		vec[i] = mini;
		minvec[i] = mini;
	}
	for(i = 1;i<n;i++){
		vec[i] = vec[i-1]+vec[i];
	}
 
	//preprocess(ar, n);
	while(q--){
		scanf("%lld %lld", &l, &r);
		l--;
		r--;
		if(l == 0){
			printf("%lld\n", vec[r]);
			continue;
		}
		int mini = ar[l];
		int sum = 0;
		j = l;
		while(j <= r && mini > minvec[l]){
			mini = min(mini, ar[j]);
			sum+=mini;
			j++;
		}
		if(j <= r){
			j--;
			sum+=(vec[r] - vec[j]);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
