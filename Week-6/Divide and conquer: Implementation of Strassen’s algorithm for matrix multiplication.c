#include <stdio.h>
void strassen(int a[2][2], int b[2][2], int c[2][2]){
    int p1, p2, p3, p4, p5, p6, p7;
    p1 = a[0][0] * (b[0][1] - b[1][1]);
    p2 = (a[0][0] + a[0][1]) * b[1][1];
    p3 = (a[1][0] + a[1][1]) * b[0][0];
    p4 = a[1][1] * (b[1][0] - b[0][0]);
    p5 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    p6 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    p7 = (a[0][0] - a[1][0]) * (b[0][0] + b[0][1]);
    
    c[0][0] = p5 + p4 - p2 + p6;
    c[0][1] = p1 + p2;
    c[1][0] = p3 + p4;
    c[1][1] = p5 + p1 - p3 - p7;
}
int main(){
    int a[2][2], b[2][2], c[2][2];
    int i, j;
    printf("Enter first matrix:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &a[i][j]);
    printf("Enter second matrix:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);
    strassen(a, b, c);
    printf("Result matrix:\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
