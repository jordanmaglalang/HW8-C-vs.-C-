#include <iostream>
#include<vector>
#include <stdexcept>
using namespace std;
class Matrix{



    private:
        int **grid;
        int m_rows;
        int m_cols; 
    public:
    
        Matrix(int rows, int cols){
            m_rows = rows;
            m_cols = cols;
            grid = new int*[m_rows];
            for(int i=0; i <m_rows; i++){
                grid[i]=new int[cols];
            }
        }
        ~Matrix(){
            for(int i=0; i < m_rows;i++){
                delete [] grid[i];
            }
            delete[]grid;
        }
        
        void setValue(int row, int col, int data){
            //cout << "iterate" << endl;
            grid[row-1][col-1]= data;

        }

        Matrix addMatrices(const Matrix& matrix_2){
            if(matrix_2.m_rows != this->m_rows || matrix_2.m_cols != this->m_cols){
                throw runtime_error("Invalid dimensions for the addition of matrices!");

            }
            Matrix sum(m_rows,m_cols);
            for(int i=0; i < m_rows; i++){
                for(int j=0; j < m_cols; j++){
                    sum.grid[i][j] = matrix_2.grid[i][j] + this->grid[i][j];
                }
            }
            //sum.displayGrid();
            return sum;

        }

        Matrix multiplyMatrices(const Matrix& matrix_2){
            if(matrix_2.m_rows != this->m_cols){
                throw runtime_error("Invalid dimensions for the multiplication of matrices!");

            }
            
            Matrix product(this->m_rows,matrix_2.m_cols);
            for(int row =0; row< this->m_rows; row++){
                for(int col=0; col < matrix_2.m_cols; col++){
                    int sum = 0;
                    for(int a= 0; a < m_cols;a++){
                        sum +=  this->grid[row][a] * matrix_2.grid[a][col];
                    }
                    product.grid[row][col] = sum;  
                }

            }
            
            //product.displayGrid();
            return product;

        }

        void displayGrid(){
            for(int i = 0; i < m_rows; i++){
                for(int j =0; j< m_cols; j++){
                    cout << this->grid[i][j] << " ";
                }
                cout << endl;
            }
        }

        void transpose(){
            Matrix newGrid(m_cols,m_rows);
           // cout << m_rows << " " << m_cols << endl;
            
            for(int i=0; i < m_cols; i++){
                for(int j=0; j < m_rows; j++){
                    newGrid.grid[i][j]=grid[j][i];
                }
            }
            
            for(int i=0; i < m_rows;i++){
                delete [] grid[i];
            }
            delete[]grid;


            m_rows = newGrid.m_rows;
            m_cols = newGrid.m_cols;

            grid = new int*[m_rows];
            for(int i =0; i < m_rows; i++){
                grid[i]=new int[m_cols];
                for(int j =0; j < m_cols; j++){
                    grid[i][j] = newGrid.grid[i][j];
                }
            }
            
        }

        void scalar(int num){
            for(int i =0; i < this->m_rows; i++){
                for(int j = 0; j < this->m_cols; j++){
                    this->grid[i][j]*= num;
                }
            }            
        }
        

};


int main(){
   
    Matrix a(2,2);
    a.setValue(1,1,6);
    a.setValue(1,2,4);
    a.setValue(2,1,8);
    a.setValue(2,2,3);
    

    
    Matrix b(2,3);
    b.setValue(1,1,1);
    b.setValue(1,2,2);
    b.setValue(1,3,3);
    b.setValue(2,1,4);
    b.setValue(2,2,5);
    b.setValue(2,3,6);
    b.scalar(3);
  

    Matrix c(2,3);
    c.setValue(1,1,2);
    c.setValue(1,2,4);
    c.setValue(1,3,6);
    c.setValue(2,1,1);
    c.setValue(2,2,3);
    c.setValue(2,3,5);
    c.transpose();
   

    Matrix d = b.multiplyMatrices(c);
    cout << "D is equal to:" << endl;
    a.addMatrices(d).displayGrid();


}