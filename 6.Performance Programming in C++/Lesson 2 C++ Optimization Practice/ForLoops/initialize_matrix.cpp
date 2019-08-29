#include "initialize_matrix.hpp"

using namespace std;
vector < vector<int> > initialize_matrix(int num_rows, int num_cols, int initial_value) {
    
    vector < vector<int> > matrix;
    vector<int> new_row;
    /*
    new_row.reserve(num_cols);
    matrix.reserve(num_rows);
    for (int j = 0; j < num_cols; j++) {
        new_row.push_back(initial_value);
    }
    
    for (int i = 0; i < num_rows; i++) {
        matrix.push_back(new_row);
    }
    */
    //more efficient
    for (int i = 0; i < num_rows; i++) {
        new_row.clear();
        for (int j = 0; j < num_cols; j++) {
            new_row.push_back(initial_value);
        }
        matrix.push_back(new_row);
    }
    
    return matrix;
}
