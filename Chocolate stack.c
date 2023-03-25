#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
 
int* solution (int N, int* C, int* out_n) {
    // Write your code here
    // Assign the size of the array to be returned into out_n variable
    // *out_n = array_size;
 
    int* stack = (int *)malloc(N*sizeof(int));
	int* sold = (int *)malloc(N*sizeof(int));
	
	for(int i=0; i<N; i++){
		stack[i] = 0;
		sold[i] = 0;
	}
	
	int stackTop, soldTop;
	stackTop = 0;
	soldTop = 0;
	for(int i=0; i<N; i++){
		if(C[i]>0){
			stack[stackTop] = C[i];
			stackTop++;
		}
		if(C[i]==0){
			sold[soldTop] = stack[stackTop - 1];
			soldTop++;
			stackTop--;
		}
	}
	
	*out_n = soldTop;
	return sold;
    
}
 
int main() {
    int out_n;
    int N;
    scanf("%d", &N);
    int i_C;
    int *C = (int *)malloc(sizeof(int)*(N));
    for(i_C = 0; i_C < N; i_C++)
    	scanf("%d", &C[i_C]);
 
    int* out_ = solution(N, C, &out_n);
    printf("%d", out_[0]);
    for(int i_out_ = 1; i_out_ < out_n; i_out_++)
    	printf(" %d", out_[i_out_]);
}
