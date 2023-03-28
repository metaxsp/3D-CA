#include<stdio.h>
#include<stdlib.h>

#define SIZE 4
//缓冲数组
int new[SIZE][SIZE][SIZE];

void top_rule(int (*ca)[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
          for(int k=0;k<SIZE;k++){
        new[i][j][k]=*(*(*(ca+i)+j)+k);
        if(i==0 || i==SIZE-1){
            if(i==SIZE-1){
            new[i][j][k] ^=*(*(*(ca)+j)+k);
            new[i][j][k] ^=*(*(*(ca+SIZE-2)+j)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+SIZE-1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+1)+j)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i+1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+i-1)+j)+k);
        }
        if(j==0 || j==SIZE-1){
            if(j==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i))+k);
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-2)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+1)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j+1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+j-1)+k);
        }
       }
       for(int i=0;i<SIZE;i++)
          for(int j=0;j<SIZE;j++)
             for(int k=0;k<SIZE;k++)
             *(*(*(ca+i)+j)+k)=new[i][j][k];
}

void front_rule(int (*ca)[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
          for(int k=0;k<SIZE;k++){
        new[i][j][k]=*(*(*(ca+i)+j)+k);
        if(i==0 || i==SIZE-1){
            if(i==SIZE-1){
            new[i][j][k] ^=*(*(*(ca)+j)+k);
            new[i][j][k] ^=*(*(*(ca+SIZE-2)+j)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+SIZE-1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+1)+j)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i+1)+j)+k);
            new[i][j][k] ^=*(*(*(ca+i-1)+j)+k);
        }
        if(k==0 || k==SIZE-1){
            if(k==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i)+j));
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-2);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+1);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+k+1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+k-1);
        }
       }
       for(int i=0;i<SIZE;i++)
          for(int j=0;j<SIZE;j++)
             for(int k=0;k<SIZE;k++)
             *(*(*(ca+i)+j)+k)=new[i][j][k];
}

void side_rule(int (*ca)[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
          for(int k=0;k<SIZE;k++){
        new[i][j][k]=*(*(*(ca+i)+j)+k);
        if(k==0 || k==SIZE-1){
            if(k==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i)+j));
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-2);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+SIZE-1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+1);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j)+k+1);
            new[i][j][k] ^=*(*(*(ca+i)+j)+k-1);
        }
        if(j==0 || j==SIZE-1){
            if(j==SIZE-1){
            new[i][j][k] ^=*(*(*(ca+i))+k);
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-2)+k);
            }
            else{
            new[i][j][k] ^=*(*(*(ca+i)+SIZE-1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+1)+k);
            }
        }
        else{
            new[i][j][k] ^=*(*(*(ca+i)+j+1)+k);
            new[i][j][k] ^=*(*(*(ca+i)+j-1)+k);
        }
       }
       for(int i=0;i<SIZE;i++)
          for(int j=0;j<SIZE;j++)
             for(int k=0;k<SIZE;k++)
             *(*(*(ca+i)+j)+k)=new[i][j][k];
}

void xor(int (*ca)[SIZE][SIZE],int (*key)[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
          for(int k=0;k<SIZE;k++){
            *(*(*(ca+i)+j)) ^=*(*(*(key+i)+j));
          }
}

void exchange_1_5(int (*ca)[SIZE][SIZE]){
    int tmp;
    for(int i=0;i<SIZE;i++){
        tmp=*(*(*(ca+i)));
        *(*(*(ca+i)))=*(*(*(ca+i)+5));
        *(*(*(ca+i)+5))=tmp;
    }
}

void encrypt(int n,int (*ca)[SIZE][SIZE]){
    for(int t=0;t<n;t++){
        top_rule(ca);
        exchange_1_5(ca);
        front_rule(ca);
        for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
        for(int k=0;k<SIZE;k++)
        printf("%d ",ca[i][j][k]);
        printf("\n");
    }
    printf("\n");
    }
}

void decrypt(int n,int (*ca)[SIZE][SIZE]){
    for(int t=0;t<n;t++){
        front_rule(ca);
        exchange_1_5(ca);
        top_rule(ca);
        for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
        for(int k=0;k<SIZE;k++)
        printf("%d ",ca[i][j][k]);
        printf("\n");
    }
    printf("\n");
    }
}
int main(){                                         
    //采用循环边界，三维可逆元胞自动机
    int ca[SIZE][SIZE][SIZE]={
        {{0,1,1,0},{1,0,1,1},{1,1,1,0},{1,1,0,0}},
        {{1,1,1,0},{1,1,1,0},{1,0,1,0},{1,1,0,1}},
        {{1,0,1,0},{1,0,1,1},{0,1,1,0},{1,0,1,1}},
        {{1,1,0,1},{1,0,0,0},{0,1,1,0},{1,0,1,0}}
    };
    //任意顺序top-front-side，非逆序仍然可逆
    //在其中添加一组异或\任意规则中任意情况取反，非逆序依旧可逆，即该二维规则是线性的
    int key[SIZE][SIZE][SIZE]={
        {{1,1,0,0},{1,0,1,1},{1,1,1,0},{1,1,0,0}},
        {{1,1,1,0},{1,0,1,0},{1,0,1,0},{1,1,0,1}},
        {{1,0,1,0},{1,0,1,1},{0,1,1,0},{1,0,1,1}},
        {{1,1,0,1},{1,0,0,0},{0,1,1,0},{1,0,1,0}}
    };
    encrypt(4,ca);
    decrypt(4,ca);
}
