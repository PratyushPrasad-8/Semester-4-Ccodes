#include<stdio.h>
#define SIZE 10
void maxMin(int arr[],int u,int v,int* max,int* min){
    if(u==v){
        *max=arr[u];
        *min=arr[u];
        return ;
    }

    int mid=u-((u-v)/2);
    int maxL,maxR,minL,minR;
    //left
    maxMin(arr,u,mid,&maxL,&minL);
    maxMin(arr,mid+1,v,&maxR,&minR);

    *max=(maxL>maxR)?maxL:maxR;
    *min=(minL<minR)?minL:minR;
}

int main(){
    int arr[]={3,2,5,6,7,1,4,5,9,1};
    int max,min;
    maxMin(arr,0,SIZE-1,&max,&min);

    printf("MAX = %d AND MIN = %d",max,min);

    return 0;
}