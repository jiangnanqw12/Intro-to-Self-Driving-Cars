#include "matrix.h"

Matrix::Matrix() {
    std::vector <std:: vector <float> > initial_grid (10, std::vector <float>(5, 0.5));
    grid = initial_grid;
    rows = initial_grid.size();
    cols = initial_grid[0].size();

}

Matrix::Matrix(std::vector <std:: vector <float> > initial_grid) {
    grid = initial_grid;
    rows = initial_grid.size();
    cols = initial_grid[0].size();
}


void Matrix::setGrid(std::vector< std::vector<float> > new_grid) {
    grid = new_grid;
    rows = new_grid.size();
    cols = new_grid[0].size();
}

std::vector< std::vector<float> > Matrix::getGrid() {
    return grid;
}

std::vector<int>::size_type Matrix::getRows() {
    return rows;
}

std::vector<int>::size_type Matrix::getCols() {
    return cols;
}

/* TODO: Define a matrix_addition function
**   INPUT: a matrix
**   OUPUT: the sum of the grid variable and the input matrix
**
** STEPS:
**  1. check that the matrix in the grid variable
**     and the input matrix have the same size
**
**     if not, throw an error like
**         throw std::invalid_argument("matrices are not the same size");
**
** 2. add the matrices together and return
**       the result as a Matrix. You can do this part
**       with nested for loops. If you use an intermediate
**       vector to store a row, the vector.clear() 
**       method might be useful.
**
*/
Matrix Matrix::matrix_addition(Matrix other)
{
    std::vector<float>::size_type rows=other.getRows();
    if ((rows!=other.getRows())||(cols!=other.getCols()))
    {
        throw std::invalid_argument("matrices are not the same size");
    }
    std::vector<std::vector<float>> matrix_sum;
    std::vector<float> row_sum;
    std::vector< std::vector<float> > othergrid=other.getGrid();
    for(int i=0;i<rows;i++)
    {
        row_sum.clear();
        for(int j=0;j<cols;j++)
        {
            row_sum.push_back(grid[i][j]+othergrid[i][j]);
        }
        matrix_sum.push_back(row_sum);
    }
    return Matrix(matrix_sum);
}

Matrix Matrix:: matrix_transpose()
{
    std::vector<std::vector<float>> result;
    std::vector<float> row_t;
    for(int i=0;i<rows;i++)
    {
        row_t.clear();
        for (int j=0;j<cols;j++)
        {
            row_t.push_back(grid[j][i]);    
        }
        result.push_back(row_t);
    }
}
/* TODO: Define a matrix_print function
** This function has no inputs and no outputs
** The purpose of the function is to display the matrix in
** the terminal using std::cout. 
**
**
** The output should look something like:
** 4    9   1   10
** 5    11  6   17
** 8    4   15  2
*/
void Matrix::matrix_print()
{
    for(int i=0;i<rows;i++)
    {
        
        for(int j=0;j<cols;j++)
        {
            std::cout<<grid[i][j];
            if (j!=cols-1)
            {
                std::cout<<" ";
            }
        }
        std::cout<<"\n";
    }
}