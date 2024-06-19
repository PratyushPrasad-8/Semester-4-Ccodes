#include<stdio.h>
#define SIZE 10

int sort(int arr[],int u,int v){
    int pivot=arr[u];
    int p=u,q=v;

    while(u<v){
        while(arr[p]<=pivot && p<=q)p++;
        while(arr[q]>=pivot && p<=q)q--;

        if(p<q){
            int temp=arr[p];
            arr[p]=arr[q];
            arr[q]=temp;
        }else{
            int temp=arr[q];
            arr[q]=arr[u];
            arr[u]=temp;

            break;
        }
    }

    return q;
}

void quickSort(int arr[],int u,int v){
    if(u<v){
        int pivotIndex=sort(arr,u,v);

        quickSort(arr,u,pivotIndex-1);
        quickSort(arr,pivotIndex+1,v);
    }
}
int main(){
    int arr[]={5,4,3,7,8,9,0,2,1,-2};

    quickSort(arr,0,SIZE-1);

    printf("AFTER SORTING :\n");
    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}