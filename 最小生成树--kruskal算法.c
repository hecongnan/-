#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAX 0x7fffffff
#define MAXSIZE 100

typedef struct{
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}Mat_Grph;

typedef struct{
    int begin;
    int end;
    int weight;
}Edge;


void create_graph(Mat_Grph* G){
    G->vertex_num = 9;
    G->edge_num = 15;
    G->vertex[0] = 'A';
    G->vertex[1] = 'B';
    G->vertex[2] = 'C';
    G->vertex[3] = 'D';
    G->vertex[4] = 'E';
    G->vertex[5] = 'F';
    G->vertex[6] = 'G';
    G->vertex[7] = 'H';
    G->vertex[8] = 'I';
    for(int i = 0; i < G->vertex_num; i++){
        for(int j = 0; j < G->vertex_num; j++){
            if(i == j){
                G->arc[i][j] = 0;
            }else{
                G->arc[i][j] = MAX;
            }
        }
    }
    //A-B A-F
    G->arc[0][1] = 10;
    G->arc[0][5] = 11;
    //B-C B-G B-I
    G->arc[1][2] = 18;
    G->arc[1][6] = 16;
    G->arc[1][8] = 12;
    //C-D C-I
    G->arc[2][3] = 22;
    G->arc[2][8] = 8;
    //D-E D-G D-H D-I
    G->arc[3][4] = 20;
    G->arc[3][6] = 24;
    G->arc[3][7] = 16;
    G->arc[3][8] = 21;
    //E-F E-H
    G->arc[4][5] = 26;
    G->arc[4][7] = 7;
    //F-G
    G->arc[5][6] = 17;
    //G-H
    G->arc[6][7] = 19;
    for(int i=0;i<G->vertex_num;i++){
        for(int j=0;j<G->vertex_num;j++){
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

void swap(Edge* edges,int i,int j){
    int temp;
    temp = edges[i].begin;
    edges[i].begin = edges[j].begin;
    edges[j].begin = temp;
    temp = edges[i].end;
    edges[i].end = edges[j].end;
    edges[j].end = temp;
    temp = edges[i].weight;
    edges[i].weight = edges[j].weight;
    edges[j].weight = temp;
}

void sortEdges(Edge edges[],int edge_num){
    for(int i =0;i<edge_num;i++){
        for(int j = i+1;j<edge_num;j++){
            if(edges[i].weight>edges[j].weight){
                swap(edges,i,j);
            }
        }
    }
}

int find(int* parent,int index){
    while(parent[index] > 0){
        index = parent[index];
    }
    return index;
}

void Kruskal(Mat_Grph G){
    Edge edges[MAXSIZE];
    int k = 0;
    for(int i = 0; i < G.vertex_num; i++){
        for(int j = i + 1; j < G.vertex_num; j++){
            if(G.arc[i][j] < MAX){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arc[i][j];
                k++;
            }
        }
    }
    sortEdges(edges, k);
    int parent[MAXSIZE];
    for(int i = 0; i < G.vertex_num; i++){
        parent[i] = 0;
    }
    int n,m;
    for(int i = 0; i < k; i++){
        n = find(parent, edges[i].begin);
        m = find(parent, edges[i].end);
        if(n != m){
            parent[n] = m;
            printf("(%c,%c) %d\n", G.vertex[edges[i].begin], G.vertex[edges[i].end], edges[i].weight);
        }
    }

}

int main(){
    Mat_Grph G;
    create_graph(&G);
    Kruskal(G);
    return 0;
}