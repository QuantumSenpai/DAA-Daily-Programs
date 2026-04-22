/*
Question:
Implement DFS (Depth First Search) traversal of a graph
using adjacency matrix.
*/

#include <stdio.h>

int g[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,1},
    {0,1,1,0,1},
    {0,0,1,1,0}
};

int visited[5]={0};

void dfs(int node){
    printf("%d ", node);
    visited[node] = 1;

    for(int i=0;i<5;i++){
        if(g[node][i] && !visited[i]){
            dfs(i);
        }
    }
}

int main(){

    printf("DFS Traversal: ");
    dfs(0);

    return 0;
}

/*
Output:
DFS Traversal: 0 1 3 2 4
*/