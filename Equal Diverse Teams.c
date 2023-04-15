#include <stdio.h>
#define MAX 100000
void quick_sort(int num[MAX], int l, int r)
{
        int pivot, i, j;
        int swap;
 
        if (l >= r)
                return;
        pivot = l;
        i = l+1;
        j = r;
        while (i < j)
        {
                if (num[i] <= num[pivot])
                        i++;
                else if (num[j] > num[pivot])
                                j--;
                else {
 
                        swap = num[i];
                        num[i] = num[j];
                        num[j] = swap;
 
                    }
        }
        if (num[i] > num[pivot])
                i--;
 
        swap = num[i];
        num[i] = num[pivot];
        num[pivot] = swap;
 
        quick_sort(num, l, i-1);
        quick_sort(num, i+1, r);
}
 
void main()
{
        int t, n, k, stack[MAX], top, input;
        short arr[MAX];
 
        scanf("%d", &t);
        while(t--) {
                scanf("%d%d", &n, &k);
                for (int i = 0; i < MAX; i++)
                        arr[i] = -1;
                top = 0;
                for (int i = 0; i < n; i++) {
                        scanf("%d", &input);
                        if(arr[input-1] == -1) {
                                arr[input - 1] = top;
                                stack[top++] = 0;
                        }
                        stack[arr[input-1]]++;
                }
                //unique_subjects = top;
                if (top < k || top > 2*k) {
                        printf("NO\n");
                        continue;
                }
                if (top == 2*k) {
                        printf("YES\n");
                        continue;
                }
                quick_sort(stack, 0, top - 1);
                int team_a = 0;
                int team_b = 0;
                for (int i = 0; i < top; i++) {
                        if (stack[i] > 1) {
                                if (team_a == team_b) {
										if (top - i == 2*(k - team_a)) {
											team_a = k;
											team_b = k;
											break;
										}
                                        team_a++;
                                        team_b++;
                                }
                                else if (team_a < team_b)
                                        team_a++;
                                else
                                        team_b++;
                        }
                        else {
                                if (team_a == team_b || (team_a < team_b))
                                        team_a++;
                                else
                                        team_b++;
                        }
                }
                if (team_a == k && team_b == k)
                        printf("YES\n");
                else
                        printf("NO\n");
        }
}
