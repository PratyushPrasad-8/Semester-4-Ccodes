#include<stdio.h>
#define V 4
#define INF 99999
void floydd(int graph[V][V]){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=k && j!=k && graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }

    printSoln(graph);
}

void printSoln(int graph[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    
    floydd(graph);
    return 0;
}