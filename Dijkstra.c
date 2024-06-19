#include<stdio.h>

#define V 9
#define MAX 999

int minDis(int dis[],int vis[]){
    int min=MAX;
    int minIndex;
    for(int i=0;i<V;i++){
        if(vis[i]==0 && dis[i]<=min){
            min=dis[i];minIndex=i;
        }
    }

    return minIndex;
}

void printSoln(int dis[]){
    for(int i=0;i<V;i++){
        printf("%d --",dis[i]);
    }
}


void dijkstra(int graph[V][V],int src){
    int dis[V];
    int vis[V];

    for(int i=0;i<V;i++){
        dis[i]=MAX;
        vis[i]=0;
    }
    dis[src]=0;

    for(int i=0;i<V-1;i++){
        int u=minDis(dis,vis);

        vis[u]=1;

        for(int j=0;j<V;j++){
            if(!vis[j] && graph[u][j] && dis[u]+graph[u][j]<dis[j]){
                dis[j]=dis[u]+graph[u][j];
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

    
    dijkstra(graph, 0);

    return 0;
}
