#include<stdio.h>

int visited[6] = {0}; // Global declaration 

void DFS(int arr[][7], int row, int n) {
    if(visited[row] == 0) {
        printf("%d ", row);
        visited[row] = 1;
    }
    for(int col = 0; col<=n; col++) {
        if(arr[row][col] == 1 && visited[col] == 0) {
            DFS(arr, col, n);
        }
    }
    
}


int main() {    



    int arr[][7] =  {  // 0  1  2  3  4  5  6 
                /*0*/    {0, 1, 0, 1, 0, 0, 0},  
                /*1*/    {1, 0, 1, 1, 0, 1, 0},  
                /*2*/    {0, 1, 0, 1, 1, 1, 0},  
                /*3*/    {1, 1, 1, 0, 1, 0, 0},  
                /*4*/    {0, 0, 1, 1, 0, 0, 1},  
                /*5*/    {0, 1, 1, 0, 0, 0, 0},  
                /*6*/    {0, 1, 0, 0, 1, 0, 0}   
                    };

    //Another example:
    // int arr[][7] =  {  // 0  1  2  3  4  5  6 
    //             /*0*/    {0, 1, 1, 1, 0, 0, 0},  
    //             /*1*/    {1, 0, 1, 0, 0, 0, 0},  
    //             /*2*/    {1, 1, 0, 1, 1, 0, 0},  
    //             /*3*/    {1, 0, 1, 0, 1, 0, 0},  
    //             /*4*/    {0, 0, 1, 1, 0, 1, 1},  
    //             /*5*/    {0, 0, 0, 0, 1, 0, 0},  
    //             /*6*/    {0, 0, 0, 0, 1, 0, 0}   
    //                 };
                    
    int start = 0;  // Vertex number starts from 0
    int end = 6; // Vertex number ends at 4
    DFS(arr, start, end);

}