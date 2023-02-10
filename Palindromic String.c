#include <stdio.h>
 
int main()
{
    int pal(char*);
    char n[100];
    scanf("%[^\n]s",n);
    if(pal(n)) printf("YES");
    else printf("NO");
}
int pal(char*n){
    int i,l,r;
    for(i=0;i<n[i];i++);
    
    for(l=0,r=i-1;l<=r;l++,r--){
        if(n[l]!=n[r]){
            return 0;
            l++;r--;
        }
        else return 1;
    }
}
