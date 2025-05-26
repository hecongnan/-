#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct{
    VertexType vexs[MAXSIZE]; // Vertex array
    EdgeType arc[MAXSIZE][MAXSIZE]; // Adjacency matrix
    int vertex_num, edge_num; // Number of vertices and edges
}Mat_Grph;

int visited[MAXSIZE]; // Visited array 
int front = 0; // Queue front
int rear = 0; // Queue rear
int queue[MAXSIZE]; // Queue array

void create_graph(Mat_Grph* G){
    G->vertex_num = 9;
    G->edge_num = 15;
    G->vexs[0] = 'A';
    G->vexs[1] = 'B';
    G->vexs[2] = 'C';
    G->vexs[3] = 'D';
    G->vexs[4] = 'E';
    G->vexs[5] = 'F';
    G->vexs[6] = 'G';
    G->vexs[7] = 'H';
    G->vexs[8] = 'I';
    for(int i=0;i<G->vertex_num;i++){
        for(int j =0;j<G->vertex_num;j++){
            G->arc[i][j] = 0;
        }
    }
    G->arc[0][1] = 1;
    G->arc[0][5] = 1;
    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;
    G->arc[2][3] = 1;
    G->arc[2][8] = 1;
    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;
    G->arc[4][5] = 1;
    G->arc[4][7] = 1;
    G->arc[5][6] = 1;
    G->arc[6][7] = 1;
    for(int i=0;i<G->vertex_num;i++){
        for(int j =0;j<G->vertex_num;j++){
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

void bfs(Mat_Grph G){
    int i = 0;
    visited[i] = 1;
    printf("%c ",G.vexs[i]);
    queue[rear++] = i;
    while(front != rear){
        i = queue[front];
        front++;
        for(int j = 0;j<G.vertex_num;j++){
            if(G.arc[i][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                printf("%c ",G.vexs[j]);
                queue[rear++] = j;
            }
        }
    }
}

int main(){
    Mat_Grph G;
    create_graph(&G);
    printf("The adjacency matrix of the graph is:\n");
    for(int i=0;i<G.vertex_num;i++){
        visited[i] = 0;
    }
    bfs(G);
    return 0;
}