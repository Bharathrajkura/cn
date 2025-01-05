#include<stdio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int G[MAX][MAX],int n,int startNode){
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX], count, mindistance, nextnode;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(G[i][j]==0){
                cost[i][j]=INFINITY;
            }else{
                cost[i][j]=G[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        distance[i]=cost[startNode][i];
        pred[i]=startNode;
        visited[i]=0;
    }
    distance[startNode]=0;
    visited[startNode]=1;
    count=1;
    while(count<n-1){
        mindistance=INFINITY;
        for(int i=0;i<n;i++){
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(int i=0;i<n;i++){
            if(!visited[i]&&mindistance+cost[nextnode][i]<distance[i]){
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
        }
        count++;
    }
    for(int i=0;i<n;i++){
        if(i!=startNode){
            printf("Distance of Node %d =%d ",i,distance[i]);
            int j=i;
            do{
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startNode);
        }
    }
}
void main(){
    int G[MAX][MAX],i,j,n,u;
    printf("Enter Number of Vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacentcy matrix: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("Enter the startung Node : ");
    scanf("%d",&u);
    dijkstra(G, n, u);
}
