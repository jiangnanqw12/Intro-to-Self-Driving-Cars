#include <iostream>
using namespace std;
int main() {
    
    //TODO: Use this as a playground to write a for loop and if statements
    // in the same program.
    
    // For example, write a for loop that iterates from 0 to 80.
    // If the iterator is greater than or equal to 0 but less than 10, 
    //      output the phrase 'slow'
    // If the iterator is between 10 inclusive
    //      and less than 30, output the phrase 'medium'
    // If the iterator is between 30 inclusive and 70, output the phrase 'fast'
    // If the iterator is greater than 70 inclusive, output the phrase 'too fast'
    for (int i=0;i<=80;i++)
    {
        if (i>=0 && i<10)
        {
            cout<<"slow"<<endl;
        }
        else if (i>=10 && i<30)
        {
            cout<<"medium"<<endl;
        }
        else if(i>=30 && i<70)
        {
            cout<<"fast"<<endl;
        }
        else if(i>70)
            cout<<"too fast"<<endl;
    }
    
    return 0;
}