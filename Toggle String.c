#include <stdio.h>
 
int main(){
	char s[101];
	scanf("%s", &s);   
	int i;
	for(i=0;i<101;i++){
		//printf("%d\n",s[i]);
		if(s[i]==0){
			break;
		}
		if(s[i]>=97 && s[i] <=122){
			s[i]-=32;
		}
		else if(s[i]>=65 && s[i]<=90){
			s[i]+=32;
		} else {
			printf("invalid input\n");
			return 1;
		}
	}
	printf("%s\n", s);       // Writing output to STDOUT
}
