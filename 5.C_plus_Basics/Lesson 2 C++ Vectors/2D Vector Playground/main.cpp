//TODO: Write a function that receives two integer matrices and outputs
// the sum of the two matrices. Then in your main() function, input a few
// examples to check your solution. Output the results of your function to 
// cout. You could even write a separate function that prints an arbitrarily 
// sized matric to cout.

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> mat_sum(vector<vector<int>> mat1,vector<vector<int>> mat2);
void mat_print(vector<vector<int>> mat);
int main()
{
    vector<vector<int>> mat1(5,vector<int>(6,1));
    vector<vector<int>> mat2(5,vector<int>(6,2));
    vector<vector<int>>matsum=mat_sum(mat1,mat2);
    mat_print(matsum);
}
vector<vector<int>> mat_sum(vector<vector<int>> mat1,vector<vector<int>> mat2)
{
    vector<vector<int>> matsum;
    vector<int> vec1;
    for(int i=0;i<mat1.size();i++)
    {   vec1.clear();
        for (int j=0;j<mat1[0].size();j++)
        {
        vec1.push_back(mat1[i][j]+mat2[i][j]);
        }
        matsum.push_back(vec1);
    }
    return matsum;
}

void mat_print(vector<vector<int>> mat)
{
    for(int i=0;i<mat.size();i++)
    {   
        for (int j=0;j<mat[0].size();j++)
        {
        cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
        
    }
}