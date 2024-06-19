#include<stdio.h>
#define SIZE 10
int binarySearch(int arr[],int target,int u,int v){
    if(u>v){
        return -1;
    }

    int mid=u-((u-v)/2);
    if(arr[mid]==target){
        return mid;
    }else if(arr[mid]>target){
        return binarySearch(arr,target,u,mid-1);
    }else{
        return binarySearch(arr,target,mid+1,v);
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};

    int pos=binarySearch(arr,7,0,SIZE-1);
    
    if(pos!=-1){
        printf("POSITION = %d",pos);
    }else{
        printf("NOT FOUND");
    }
    return 0;
}
