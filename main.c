#include <stdio.h>
#include <stdlib.h>
#define ROWS 2
#define COLS 2

int** makeMatrix(int rows, int cols){
    int ** matrix= (int**)malloc(rows*sizeof(int*));
    for(int i = 0;i<rows; i++){
        matrix[i] = (int*)malloc(cols* sizeof(int));
    }

    return matrix;
}

void clearMatrix(int ** matrix, int rows){
    for(int i=0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void displayGrid(int rows, int cols,int** matrix){
    for(int i=0;i< rows;i++){
        for(int j=0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int addMatrices(int** matrix1, int** matrix2, int** final_matrix, int rows1, int cols1, int rows2, int cols2){
    if(rows1 != rows2 || cols1 != cols2){
       printf("Invalid dimensions for the addition of matrices!");
       return -1; 
    }
    for (int i=0;i<rows1; i++ ){
        for(int j=0; j < cols1; j++){
            final_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }

    }
    return 0;
    

}
int multiplyMatrices(int** matrix1, int** matrix2, int** final_matrix, int rows1, int cols1, int rows2, int cols2){
    if(cols1 != rows2){
        printf("Invalid dimensions for the multiplication of matrices!");

        return -1;
    }
    for (int curr_row=0; curr_row < rows1; curr_row++ ){

        for(int curr_col=0; curr_col < cols2; curr_col++){
            int sum = 0;
            for(int a =0; a < cols1; a++){
                sum+= matrix1[curr_row][a] * matrix2[a][curr_col];
            }
            final_matrix[curr_row][curr_col] = sum;


        }
    }

    //displayGrid(rows1, cols2, final_matrix);

    return 0;
    

}

void transpose(int** matrix1, int** final_matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j=0; j < cols; j++){
            final_matrix[i][j]=matrix1[j][i];
        }
    }
    
   //displayGrid(cols, rows, final_matrix);
}

void scalar(int** matrix, int rows, int cols, int num){
    for(int i =0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j]*= num;
        }
    }   
}





int main(){
    
    
    

    int** a= makeMatrix(2,2);
    a[0][0] = 6;
    a[0][1] = 4;
    a[1][0]=8;
    a[1][1]=3;
   
   printf("Matrix A:\n");
   displayGrid(2,2,a);
   printf("\n");
    
   int** b= makeMatrix(2,3);
   printf("\n");
   b[0][0] = 1;
   b[0][1] = 2;
   b[0][2] = 3;
   b[1][0]= 4;
   b[1][1] = 5;
   b[1][2] = 6;
   
   scalar(b,2,3,3);
   printf("Matrix B after scalar multiplication:\n");
   displayGrid(2,3,b);
   printf("\n");

   int** c= makeMatrix(2,3);
   c[0][0] = 2;
   c[0][1] = 4;
   c[0][2] = 6;
   c[1][0] = 1;
   c[1][1]= 3;
   c[1][2]=5;
    
   int** transpose_c = makeMatrix(3,2);
   transpose(c, transpose_c, 3,2);
   printf("Matrix C after transpose:\n");
   displayGrid(3,2,b);
   printf("\n");
    
   int ** product = makeMatrix(2,2);
   multiplyMatrices(b,transpose_c,product, 2,3,3,2);

   printf("Matrix product after multiplication:\n");
   displayGrid(2,2,product);
   printf("\n");
    
    

   int ** sum = makeMatrix(2,2);
   addMatrices(a, product,sum, 2,2,2,2);
   printf("D is equal to:\n");
   displayGrid(2,2,sum);
    
    return 0;
}
