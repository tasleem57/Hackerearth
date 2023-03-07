#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
 
bool make_equal (char* T, char* S) {
 
    int n = strlen(T);
    if (n < 1)
        return false;
    if (n>100000)
        return false;
    if (n != strlen(S))
        return false;
 
    int i, j;
    for (i = 0; i < n; i++) {
        //printf("1. i = %d S = %c T = %c\n", i, S[i], T[i]);
        if (S[i] != T[i]) 
        {
            if (S[n-i-1] == T[i]) {
                // swap
                //printf("Swap case 2\n"); 
                char temp = S[i];
                S[i] = S[n-i-1];
                S[n-i-1] = temp;
            }
            else 
            {
                //printf("Swap case 1\n");
                char temp = S[i];
                S[i] = T[i];
                T[i] = temp;
        
                temp = T[i];
                T[i] = T[n-i-1];
                T[n-i-1] = temp;
        
            }
            //printf("2. i = %d S = %c T = %c\n\n", i, S[i], T[i]);
            if (S[i] != T[i])
                return false; 
        }
        
    }
    return true;
}
 
int main() {
    char* T = (char*)malloc(200000 * sizeof(char));
    scanf("\n%[^\n]s", T);
    char* S = (char*)malloc(200000 * sizeof(char));
    scanf("\n%[^\n]s", S);
 
    bool out_ = make_equal(T, S);
    //printf("%d", out_ ? 1 : 0);
 
    if (out_)
        printf("YES\n");
    else
        printf("NO\n");
}
