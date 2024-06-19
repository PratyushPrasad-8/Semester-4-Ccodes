#include<stdio.h>
#define V 9
#define MAX 99999

void printSoln(int dis[]){
    for(int i=0;i<V;i++){
        printf("%d --",dis[i]);
    }
}

void bellman(int graph[V][V],int src){
    int dis[V];

    for(int i=0;i<V;i++){
        dis[i]=MAX;
    }
    dis[src]=0;

    for(int i=0;i<V-1;i++){
        for(int j=0;j<V;j++){
            printf("ok");
            if(i!=j && dis[i]!=MAX && graph[i][j]!=0 && dis[i]+graph[i][j]<dis[j]){
                dis[j]=dis[i]+graph[i][j];
            }
        }
    }

    printSoln(dis);
}

int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    
    bellman(graph, 0);
    return 0;
}