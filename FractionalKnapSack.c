#include<stdio.h>
#define SIZE 3
void sort(int ratio[],int profit[],int weight[]){
    for(int i=0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                int temp;
                //swap ratio
                temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp;

                //swap profit
                temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;

                //swap weight
                temp=weight[j];
                weight[j]=weight[j=1];
                weight[j+1]=temp;
            }
        }
    }
}

int main(){
    int profit[]={100,60,120};
    int weight[]={20,10,30};
    int capacity=50;

    int ratio[SIZE];
    for(int i=0;i<SIZE;i++){
        ratio[i]=profit[i]/weight[i];
    }

    sort(ratio,profit,weight);

    for(int i=0;i<SIZE;i++){
        printf(" %d--",weight[i]);
    }

    //fractionalKanpSack(profit,weight,capacity);
    return 0;
}