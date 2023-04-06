#include <stdio.h>
 
int main(){
	int N;
	scanf("%d", &N);
	
	long data[N];
	for(int i=0; i<N; i++)
	    scanf("%ld", &data[i]);
	
    // write your code here
    // ans = 
	if (data[N-1]%10 == 0) {
		printf("Yes");
	} else {
		printf("No");
	}
    
    
    return 0;
}
