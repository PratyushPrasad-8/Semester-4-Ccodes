#include<stdio.h>
#define SIZE 5

void sort(int profit[],int deadLine[]){
    for(int i=0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(profit[j]<profit[j+1]){
                int temp;
                temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;

                temp=deadLine[j];
                deadLine[j]=deadLine[j+1];
                deadLine[j+1]=temp;
            }
        }
    }
}

int findMax(int deadLine[]){
    int max=0;
    for(int i=0;i<SIZE;i++){
        max=(max>deadLine[i])?max:deadLine[i];
    }
    
    for(int i=0;i<SIZE;i++){
        max=(max>deadLine[i])?max:deadLine[i];
    }
    
    return max;
}

int main(){
    int deadLine[]={2,1,2,1,3};
    int profit[]={100,19,27,25,15};
    int n=findMax(deadLine)+1;
    int ans[n];

    sort(profit,deadLine);

    for(int i=0;i<n;i++){
        ans[i]=-1;
    }

    for(int i=0;i<SIZE;i++){
        int p=deadLine[i];
        while(ans[p]!=-1 && p>0)p--;
        if(p!=0){
            ans[p]=profit[i];
        }
    }
    int finalAns=0;
    for(int i=1;i<n;i++){
        finalAns+=ans[i];
    }

    printf("MAX PROFIT = %d",finalAns);
    return 0;
}