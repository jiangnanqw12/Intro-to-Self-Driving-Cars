#include <iostream>
#include <vector>
#include "matrix.h"
using namespace std;
int main () {
    
    // TODO: Nothing to do here
    
    vector<vector<float>> mat1(4,vector<float>(5,1));
    vector<vector<float>> mat2(4,vector<float>(5,2));
    Matrix matrixone=Matrix(mat1);
    Matrix matrixtwo=Matrix(mat2);
    Matrix matrixthree=matrixone.matrix_addition(matrixtwo);
    matrixthree.matrix_print();
    
    return 0;
}