#include <iostream>

class Solution {
public:
  int mySqrt(int x) {
    // TODO: Write your code h
    if (x == 1)
    {
	    return 1;
    }
    float root = (float)x/2;
    while (root*root -x > 0.1 || root*root - x < -0.1)
    {
	if (root * root > x)
	{
		root = (root)/2;
	}
	else if ( root * root < x )
	{
		root = (root + x)/2; 
	}
	else
	{
		return (int) root;
	}
  }
    return (int) root;
  }
};


int main ()
{
	Solution sol;
	std::cout << "Square root is: " << sol.mySqrt(81) << std::endl;
}
