#include<stdio.h>
#define SIZE 5
#define MAX 99999

int cal(int arr[],int i,int j){
    if(i==j){
        return 0;
    }
    int min=MAX;
    for(int k=i;k<j;k++){
        int res=cal(arr,i,k)+cal(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        min=(min<res)?min:res;
    }
    return min;
}

int main(){
    int arr[]={1,2,3,4,3};

    int ans=cal(arr,1,SIZE-1);
    printf("%d",ans);
    return 0;
}