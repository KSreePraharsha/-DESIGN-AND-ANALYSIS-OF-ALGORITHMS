#include <stdio.h>
int parent[20];
int find(int i){
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int a, int b){
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}
int main(){
    int n, e;
    int i, j;
    int u, v, w;
    int edges[50][3];
    int temp[3];
    int count = 0, cost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (source destination weight):\n");
    for (i = 0; i < e; i++){
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    for (i = 0; i < e - 1; i++){
        for (j = 0; j < e - i - 1; j++){
            if (edges[j][2] > edges[j + 1][2]){
                temp[0] = edges[j][0];
                temp[1] = edges[j][1];
                temp[2] = edges[j][2];

                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];

                edges[j + 1][0] = temp[0];
                edges[j + 1][1] = temp[1];
                edges[j + 1][2] = temp[2];
            }
        }
    }
    for (i = 0; i < n; i++)
        parent[i] = i;
    printf("\nEdges in MST:\n");
    for (i = 0; i < e; i++){
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        if (find(u) != find(v)){
            printf("%d - %d = %d\n", u, v, w);
            cost = cost + w;
            unionSet(u, v);
            count++;
            if (count == n - 1)
                break;
        }
    }
    printf("Minimum cost = %d\n", cost);
    return 0;
}
