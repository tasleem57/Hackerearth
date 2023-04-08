#include<stdio.h>
#include<stdbool.h>
int board[11][11];
int noOfQueens;
 
bool isQueenSafeOrNot (int row, int col) {
    // coloumn check
    for (int index1 = 0; index1 < row; index1++)
        if (board[index1][col] == 1)
            return false;
 
 
  //upper right diagnoal 
    int index1 = row; int index2 = col;
    while(index1 >= 0 && index2 < noOfQueens){
        if(board[index1][index2] == 1)
            return false;
        index1--; index2++;    
    }
 
    //upper left diagnoal
    index1 = row; index2 = col;
    while(index1 >= 0 && index2 >= 0)
    {
        if(board[index1][index2] == 1)
            return false;
        index1--; index2--;
    }
    return true;
}
 
bool solve(int row)
{
  if(row >= noOfQueens)
    return true;
 
     for(int index3 = 0; index3 < noOfQueens; index3++)
     {
        if (isQueenSafeOrNot (row,index3)) {
            board[row][index3] = 1;
            if (solve (row + 1))
                return true;
            board[row][index3]=0;
            }
        }
        return false;
}
void print1()
{
    for(int index3 = 0; index3 < noOfQueens; index3++)
    {
        for(int index2 = 0; index2 < noOfQueens; index2++)
        {
            printf("%d ",board[index3][index2]);
        }
        printf("\n");
    }
}
 
int main()
{
    scanf("%d", &noOfQueens);
    for(int index3 = 0; index3 < noOfQueens; index3++)
        for(int index2 = 0; index2 < noOfQueens; index2++)
            board[index3][index2]=0;
 
    if(solve(0))
        print1();
    else
        printf("Not possible");
}
