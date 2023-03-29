
#include<stdio.h>
 
int main()
 
{
 
    char a[9];
 
    scanf("%s",&a);
 
    if(a[2]!='A'&& a[2]!='E'&& a[2]!='I'&& a[2]!='O'&& a[2]!='U'&& a[2]!='Y'&& (a[0]+a[1])%2==0 && (a[3]+a[4])%2==0 && (a[4]+a[5])%2==0 && (a[7]+a[8])%2==0){
 
    printf("valid");}
 
    else{
 
    printf("invalid");}
 
 
 
 
    return 0;
 
}
