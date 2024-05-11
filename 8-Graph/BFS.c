#include<stdio.h>

void BFS(int arr[][5], int i, int n) {
    printf("%d ", i); // 'i' represents the starting vertex
    int visited[5] = {0}; // size of visited array is equal to number of vertices
    visited[i] = 1; // since first vertex is visited already
    int u, v; // variables to represent rows and coloumns of array
    int q[20];
    int front = 0, rear = 0;
    q[rear] = i;

    while(front<=rear) {
        u = q[front++];
        for(v=0; v<=n; v++) {
            if(arr[u][v] == 1 && visited[v] == 0) {
                printf("%d ",v);
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }
} 


int main() {
    int arr[][5] = { 
                    {0, 1, 1, 1, 0},
                    {1, 0, 1, 0, 0},
                    {1, 1, 0, 1, 1},
                    {1, 0, 1, 0, 1},
                    {0, 0, 1, 1, 0}
                    };

                    
    int start = 0;  // Vertex number starts from 0
    int end = 4; // Vertex number ends at 4
    BFS(arr, start, end);

}