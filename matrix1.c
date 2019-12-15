// C program to multiply two square matrices. 
#include <stdio.h> 
#define N (10240) 
  
// This function multiplies mat1[][] and mat2[][], 
// and stores the result in res[][] 
void multiply(int mat1[][N], int mat2[][N], int res[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k]*mat2[k][j]; 
        } 
    } 
} 
  
int main() 
{ 
 int mat1[N][N];
 int mat2[N][N];
  
    int res[N][N]; // To store result 
    int i, j; 
    multiply(mat1, mat2, res); 

    printf("Size of Matrix; %d \n",sizeof(mat1));
    /*
    printf("Result matrix is \n"); 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
           printf("%d ", res[i][j]); 
        printf("\n"); 
    } 
    */
    return 0; 
} 
