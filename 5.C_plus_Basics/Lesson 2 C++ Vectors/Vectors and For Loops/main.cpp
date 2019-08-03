//TODO: include the iostream and vector libraries
#include<iostream>
#include<vector>
//TODO: Use the standard namespace
using namespace std;
int main() {
    
    // Part 1: declare and define a vector with values
    //        {5.0, 5.0, 5.0} and print 
    //         the vector to the terminal using cout
    // Hint: the syntax vector<datatype> varname(length, value) might help

    // Part 2: Use push back to add the values 3.0, 2.5, 1.4 
    //      to the back of the vector

    // Part 3: Print out the vector again using cout

    // Part 4: Use the vector assign method to override the current vector. 
    // The overriden vector should have 3 elements with 
    // the values {5.0, 5.0, 5.0}

    // Part 5: Print out the vector
    vector<float> vec1(3,5.0);
    for(int i=0;i<vec1.size();i++)
    {
        cout<<vec1[i]<<" ";
    }
    vec1.push_back(3.0);
    vec1.push_back(2.5);
    vec1.push_back(1.4);
    for(int i=0;i<vec1.size();i++)
    {
        cout<<vec1[i]<<" ";
    }
    vec1.assign(3,5.0);
    cout<<endl;
    for(int i=0;i<vec1.size();i++)
    {
        cout<<vec1[i]<<" ";
    }
    return 0;
}