#include<stdio.h>

#define SIZE 8
void top_rule(int (*ca)[SIZE]){
    int new[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++){
        new[i][j]=*(*(ca+i)+j);
        if(i==0 || i==SIZE-1){
            if(i==SIZE-1){
            new[i][j] ^=*(*(ca)+j);
            new[i][j] ^=*(*(ca+SIZE-2)+j);
            }
            else{
            new[i][j] ^=*(*(ca+SIZE-1)+j);
            new[i][j] ^=*(*(ca+1)+j);
            }
        }
        else{
            new[i][j] ^=*(*(ca+i+1)+j);
            new[i][j] ^=*(*(ca+i-1)+j);
        }
        if(j==0 || j==SIZE-1){
            if(j==SIZE-1){
            new[i][j] ^=*(*(ca+i));
            new[i][j] ^=*(*(ca+i)+SIZE-2);
            }
            else{
            new[i][j] ^=*(*(ca+i)+SIZE-1);
            new[i][j] ^=*(*(ca+i)+1);
            }
        }
        else{
            new[i][j] ^=*(*(ca+i)+j+1);
            new[i][j] ^=*(*(ca+i)+j-1);
        }
       }
       for(int i=0;i<SIZE;i++)
          for(int j=0;j<SIZE;j++)
             *(*(ca+i)+j)=new[i][j];
}
/*
void front_rule
void side_rule
*/

int main(){                                         
    //采用循环边界，三维可逆元胞自动机验证
    int ca[SIZE][SIZE]={
        {0,1,1,0,1,0,1,1},
        {1,1,1,0,1,1,0,0},
        {1,0,1,0,1,0,1,1},
        {1,1,0,1,1,1,0,0},
        {1,1,1,0,1,0,1,1},
        {1,0,1,0,1,0,1,0},
        {1,1,1,0,1,0,1,1},
        {1,1,0,1,1,0,0,0}
    };
    for(int i=0;i<4;i++){
        top_rule(ca);
        for(int i=0;i<SIZE;i++){
       for(int j=0;j<SIZE;j++)
        printf("%d ",ca[i][j]);
        printf("\n");
    }
    printf("\n");
    }
}