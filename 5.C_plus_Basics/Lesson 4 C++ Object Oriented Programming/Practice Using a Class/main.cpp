#include <iostream>
using namespace std;
// class declaration
class Gaussian
{
	private:
		float mu, sigma2;

	public:
		
		// constructor functions
		Gaussian ();
		Gaussian (float, float);

		// changes value of average and standard deviation 
		void setMu(float);
		void setSigma2(float);

		// outputs value of average and standard deviation
		float getMu();
		float getSigma2();

		// class methods
		float evaluate (float);
		Gaussian mul (Gaussian);
		Gaussian add (Gaussian);
};

int main ()
{
 /*
TODO: Instantiate a Gaussian object called gaussianone.The object
should have mean = 40.0 and variance (aka sigma2) = 225.0
*/
Gaussian gaussianone(40,225);
/*
TODO: Instantiate another Gaussian object called gaussiantwo. 
The object should have mean = 35.6 and variance = 12.25
*/
Gaussian gaussiatwo(35.6,12.25);
/*
TODO:
Output to the terminal the following (hint: use the std namespace with cout or
use std::cout):
- the probability density function value for gaussianone when x = 10.5
- the probability density function value for gaussianone when x = 55.4
- the probability density function value for gaussiantwo when x = 35.6
- the probability density function value for gaussiantwo when x = 29.4
*/
cout<<"gaussianone when x = 10.5:"<<gaussianone.evaluate(10.5)<<endl;
cout<<"gaussianone when x = 55.4:"<<gaussianone.evaluate(55.4)<<endl;
cout<<"gaussiantwo when x = 35.6:"<<gaussianone.evaluate(35.6)<<endl;
cout<<"gaussiantwo when x = 29.4:"<<gaussianone.evaluate(29.4)<<endl;
/*
TODO:
- Change the mean value of gaussianone to mean = 45
- Change the variance of gaussiantwo to variance = 15.4
- Output the mean of gaussianone to the terminal
- Output the variance of gaussiantwo to the terminal
*/
gaussianone.setMu(45);
gaussiatwo.setSigma2(15.4);
cout<<"gaussianone.getMu:"<<gaussianone.getMu()<<endl;
cout<<"gaussiatwo.getSigma2:"<<gaussiatwo.getSigma2()<<endl;
/*
TODO:
- Multiply gaussian one and gaussian two. Store the resulting gaussian
in a variable called gaussianthree
- Output the mean and variance of gaussianthree to the terminal
- Add gaussian one and gaussian two. Store the resulting gaussian in a 
variable called gaussianfour
- Output the mean and variance of gaussianfour to the terminal
*/

Gaussian gaussianthree,gaussianfour;
gaussianthree=gaussianone.mul(gaussiatwo);
cout<<"gaussianthree mean and variance is "<<gaussianthree.getMu()<<" and "<<gaussianthree.getSigma2()<<endl;
gaussianfour=gaussianone.add(gaussiatwo);
cout<<"gaussianfour mean and variance is "<<gaussianfour.getMu()<<" and "<<gaussianfour.getSigma2()<<endl;

    
    
    
    
    
}