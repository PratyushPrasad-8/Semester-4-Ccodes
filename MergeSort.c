#include<stdio.h>
#define SIZE 10

void merge(int arr[],int a1,int a2,int b1,int b2){
    int temp[b2-a1+1];
    int p=a1,q=b1,k=0;

    while(p<=a2 && q<=b2){
        if(arr[p]<arr[q]){
            temp[k++]=arr[p++];
        }else{
            temp[k++]=arr[q++];
        }
    }

    while(p<=a2){
        temp[k++]=arr[p++];
    }

    while(q<=b2){
        temp[k++]=arr[q++];
    }

    for(int i=0;i<k;i++){
        arr[a1+i]=temp[i];
    }
}

void mergeSort(int arr[],int u,int v){
    if(u<v){
        int mid=u-((u-v)/2);

        mergeSort(arr,u,mid);
        mergeSort(arr,mid+1,v);
        merge(arr,u,mid,mid+1,v);
    }
}

int main(){
    int arr[]={5,4,3,7,8,9,0,2,1,-2};

    mergeSort(arr,0,SIZE-1);

    printf("AFTER SORTING :\n");
    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
}