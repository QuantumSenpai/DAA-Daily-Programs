/*
Question:
Implement BFS (Breadth First Search) traversal of a graph
using adjacency matrix.
*/

#include <stdio.h>

int main(){

    int g[5][5] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,1},
        {0,0,1,1,0}
    };

    int visited[5]={0};
    int q[10], front=0, rear=0;

    q[rear++] = 0;
    visited[0] = 1;

    printf("BFS Traversal: ");

    while(front < rear){

        int node = q[front++];
        printf("%d ", node);

        for(int i=0;i<5;i++){
            if(g[node][i] && !visited[i]){
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }

    return 0;
}

/*
Output:
BFS Traversal: 0 1 2 3 4
*/