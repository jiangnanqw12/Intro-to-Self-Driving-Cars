// TODO: Include the iostream and vector libraries
#include<iostream>
#include<vector>
// TODO: Use the standard namespace
using namespace std;
// TODO: Write a main function
void vec_print(vector<float> vec);
int main() 
// TODO: Inside the main function, do the following:
/***       
 * 1. declare a float vector with 4 elements 
 * 2. fill the float vector with the following values: 4.5, 2.1, 8.54, 9.0
 * 
 * 3. declare and define a float vector with one line of code. The float vector
 * should have four elements with the following values: 3.5, 3.5, 3.5, 3.5
 * 
 * NOTE: You cannot use the bracket syntax because
 * the classroom compiles your code with C++98. The bracket syntax was introduced 
 * in C++11.
 ***/
{
vector<float> vec1(4);
vec1[0]=4.5;
vec1[1]=2.1;
vec1[2]=8.54;
vec1[3]=9.0;

vector<float> vec2(4,3.5);
vec_print(vec1);
vec_print(vec2);
}
void vec_print(vector<float> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
