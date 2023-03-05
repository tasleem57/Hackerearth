#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
 
long long solve (int N, int start, int finish, int* Ticket_cost) {
    long long total=0,path_1=0,path_2=0;
    int temp;
    if(start>finish){
        temp=start;
        start=finish;
        finish=temp;
    }
    for(int i=0;i<N;i++)
        total+=Ticket_cost[i];
    for(int i=(start-1);i<(finish-1);i++)
        path_1+=Ticket_cost[i];
    path_2=total-path_1;
    if(path_1<path_2)
        return path_1;
    else
        return path_2;
    
}
 
int main() {
    int N;
    scanf("%d", &N);
    int start;
    scanf("%d", &start);
    int finish;
    scanf("%d", &finish);
    int i_Ticket_cost;
    int *Ticket_cost = (int *)malloc(sizeof(int)*(N));
    for(i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    	scanf("%d", &Ticket_cost[i_Ticket_cost]);
 
    long long out_ = solve(N, start, finish, Ticket_cost);
    printf("%lld", out_);
}
