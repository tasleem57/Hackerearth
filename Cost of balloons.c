#include <stdio.h>
 
int main(){
	
	int Tcases;
	scanf("%d", &Tcases);
 
	while(Tcases--){
 
		int cost_green;
		scanf("%d", &cost_green);
 
		int cost_purple;
		scanf("%d", &cost_purple);
 
		int nop;
		scanf("%d", &nop);
 
		int cum1 = 0;
		int cum2 = 0;
		int inp1, inp2;
		while(nop--){
			
			scanf("%d", &inp1);
			cum1 += inp1;
 
			scanf("%d", &inp2);
			cum2 += inp2;
 
		}
 
		int cost1 = cost_green*cum1 + cost_purple*cum2;
		int cost2 = cost_green*cum2 + cost_purple*cum1;
 
		if(cost1<cost2){
			printf("%d\n", cost1);
		}else{
			printf("%d\n", cost2);
		}
 
 
 
 
 
	}
 
 
 
 
 
 
 
}
