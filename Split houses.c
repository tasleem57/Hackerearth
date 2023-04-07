#include<stdio.h>
 
int main()
{   int  i, n;
    char ch[20];
    scanf("%d",&n);
    scanf("%s",&ch);
    for(i=0; i<n; i++) {
        if(ch[i]=='H' && ch[i+1]=='H') {
            printf("NO");
            return 0;
        }
        else if(ch[i]=='.')
            ch[i]='B';
            }
 
        printf("YES\n");
    
    for(i=0; i<n; i++)
        printf("%c",ch[i]);
 
return 0;
}
