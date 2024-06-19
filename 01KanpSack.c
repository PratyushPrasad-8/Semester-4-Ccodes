#include<stdio.h>
#define SIZE 3
int rec(int profit[],int weight[],int cap,int n){
    if(n==0 || cap==0){
        return 0;
    }

    if(weight[n-1]>cap){
        return rec(profit,weight,cap,n-1);
    }else{
        int r1=profit[n-1]+rec(profit,weight,cap-weight[n-1],n-1);
        int r2=rec(profit,weight,cap,n-1);
        return (r1>r2)?r1:r2;
    }
}
int main(){
    int profit[]={100,60,120};
    int weight[]={20,10,30};
    int capacity=50;

    printf("MAXIMUM PROFIT :%d",rec(profit,weight,capacity,SIZE));
    return 0;
}