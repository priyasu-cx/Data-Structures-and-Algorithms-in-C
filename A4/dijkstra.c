#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode){
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    //pred[] stores the predecessor of each node
    //count gives the number of nodes
    //create a cost matrix
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }
    //initialize pred[], distance[] and visited[]
    for(i=0; i<n; i++){
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i]= 0;
    }
    distance[startnode]= 0;
    visited[startnode]= 1;
    count= 1;
    while(count < n-1){
        mindistance= INFINITY;
        //nextnode gives the node at minimum distance
        for(i=0; i<n; i++)
            if(distance[i]<mindistance && !visited[i]){
                mindistance = distance[i];
                nextnode = i;
            }
        //check if a better path exits through nextnode
        visited[nextnode] = 1;
        for(i=0; i<n; i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i] < distance[i]){
                    distance[i] = mindistance+cost[nextnode][i];
                    pred[i]= nextnode;
                }
        count++;
    }
    //print the path and distance of each node
    for(i=0;i<n; i++)
        if(i!=startnode){
            printf("\nDistance of node %d = %d", i+1, distance[i]);
            printf("\nPath = %d", i+1);
            j=i;
            do{
                j = pred[j];
                printf("<-%d", j+1);
            }
            while(j!=startnode);
        }
}


int main(){
    int G[MAX][MAX], i, j, n, u;
    FILE *f = fopen("dijkstra.txt", "r");
    printf("\n******DETERMINATION OF SHORTEST ROUTE******\n");
    //printf("Enter no. of vertices: ");
    //scanf("%d", &n);
    fscanf(f, "%d", &n);
    //printf("\nEnter the adjacency matrix: \n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            //scanf("%d", &G[i][j]);
            fscanf(f,"%d",&G[i][j]);
    //printf("\nEnter the starting node: ");
    //scanf("%d", &u);
    fscanf(f, "%d", &u);
    printf("Starting Node = %d\n", u+1);
    dijkstra(G,n,u);
    return 0;
}
