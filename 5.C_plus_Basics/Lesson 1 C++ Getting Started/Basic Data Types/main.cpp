#include <iostream>

int main() {
    
    // TODO: define two floating point numbers. Assign 12.07 to the
    // first floating point number. Assign 65.102 to the 
    // second floating point number.
    float float_one=12.07;
    float float_two=65.102;
    
    // TODO: Calculate the sum of the two floating point variables into
    // the float_sum variable.
    
    float float_sum;
    float_sum=float_one+float_two; 
    std::cout << float_sum << std::endl;
    
    // TODO: Calculate difference between the second and first number
    // output the results to cout. 
    float float_diff=float_two-float_one;
    std::cout<<float_one<<std::endl;
    // TODO: Calculate second_float / first_float and output the results
    // to cout.
    float float_quotient=float_two/float_one;
    std::cout<<float_quotient<<std::endl;
    // TODO: Calculate the product of the two numbers and output the results
    // to cout.
    float float_product=float_two*float_two;
    std::cout<<float_product<<std::endl;
    return 0;
}