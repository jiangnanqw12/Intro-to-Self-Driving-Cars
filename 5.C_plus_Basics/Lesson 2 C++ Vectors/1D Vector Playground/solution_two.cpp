#include <iostream>
#include <vector>

using namespace std;

// function declaration
vector<float> vectormultiply(vector<float> vector1, vector<float> vector2);

// program that computes the element-wise multiplication of two vectors
int main() {

	// declare and initialize vectors
	vector<float> v1(5);
	vector<float> v2(5);
	
	v1[0] = 17.0;
	v1[1] = 10.0;
	v1[2] = 31.0;
	v1[3] = 5.0;
	v1[4] = 7.0;

	v2[0] = 3.0;
	v2[1] = 1.0;
	v2[2] = 6.0;
	v2[3] = 19.0;
	v2[4] = 8.0;

	vector<float> v3 (v1.size());

	// calculate the difference between the two vectors
	v3 = vectormultiply(v1, v2);

	// print out the results of the vector multiplication
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	}

	cout << endl;
	
	return 0;

}

// define the function - 
// INPUTS: two vectors
// OUTPUT: multiplies elements together into a new vector
vector<float> vectormultiply(vector<float> vector1, vector<float> vector2) {

	vector<float> vectorproduct (vector1.size());

	for (int i = 0; i < vector1.size(); i++) {
		vectorproduct[i] = vector1[i] * vector2[i];
	}

	return vectorproduct;

}