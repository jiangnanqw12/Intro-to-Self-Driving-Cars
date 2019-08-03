//TODO: include the iostream and vector libraries
#include<iostream>
#include<vector>
//TODO: Use the standard namespace
using namespace std;

//TODO:
// Fill out your program's header. The header should contain any necessary
// include statements and also function declarations
vector<int> vec_diff(vector<int> vec1,vector<int> vec2);
vector<int> vec_mul(vector<int> vec1,vector<int> vec2);
void vec_print(vector<int> vec);

//TODO:
// Write your main program. Remember that all C++ programs need
// a main function. The most important part of your program goes
// inside the main function. 
int main()
{
    vector<int> vec1={5,10,27};
    vector<int> vec2={3,17,12};
    vector<int> vecdiff=vec_diff(vec1,vec2);
    vec_print(vecdiff);
    vector<int> vec3={17,10,31,5,7};
    vector<int> vec4={3,1,6,19,8};
    vector<int> vecmul=vec_mul(vec3,vec4);
    vec_print(vecmul);
}
vector<int> vec_diff(vector<int> vec1,vector<int> vec2)
{
    vector<int> vecdif;
    for (int i=0;i<vec1.size();i++)
    {
        vecdif.push_back(vec1[i]-vec2[i]);
    }
    return vecdif;
}
vector<int> vec_mul(vector<int> vec1,vector<int> vec2)
{
    vector<int> vecmul;
    for (int i=0;i<vec1.size();i++)
    {
        vecmul.push_back(vec1[i]*vec2[i]);
    }
    return vecmul; 
}
void vec_print(vector<int> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}