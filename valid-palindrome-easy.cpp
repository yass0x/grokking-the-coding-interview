#include <iostream>

class Solution 
{
	public: 
		bool isPalindrome (std::string	s)
		{
			int leftIndex = 0, rightIndex = s.length () - 1;
			while(leftIndex < rightIndex)
			{
				while(leftIndex < rightIndex && std::isalnum(s[leftIndex]) ==0)
				{
					leftIndex++;
				}
				while (leftIndex < rightIndex && std::isalnum(s[rightIndex]) == 0)
				{
					rightIndex --;
				}
				if (std:: tolower(s[leftIndex]) == std::tolower(s[rightIndex]))
				{
					leftIndex++;
					rightIndex --;

				}
				else
				{
					
					std::cout << leftIndex << " " << rightIndex << " " << s[leftIndex] << " " << s[rightIndex];
				      return false; 	
				}
			}
			return true;
		}
};

int main() 
{
	Solution sol;
	std::string input_string = "A man, a plan, a canal, Panama!";
	bool ret_val = sol.isPalindrome(input_string);
	std:: cout << "Solution is: " << ret_val << std::endl; 
	       	
}
