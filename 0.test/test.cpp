#include<iostream>
#include<vector>
using namespace std;


void mat_print(vector<vector<float>> vec1)
{
    for (int i=0;i<vec1.size();i++)
    {
        for (int j=0;j<vec1[0].size();j++)
        {
            cout<<vec1[i][j]<<" ";
        }
        cout<<endl;
    }
}
