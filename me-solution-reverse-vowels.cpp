# include <iostream>
# include <vector>
# include <string>

class Solution
{
	public: 
		std::string string_vowels = "aeiouAEIOU";
		std::string  reverse_vowels(std::string s)
		{
			std::vector<char> array_from_s(s.begin(), s.end());
			int leftIndex = 0, rightIndex = s.length() -1;
			while(leftIndex < rightIndex)
			{	
				while (leftIndex < rightIndex && string_vowels.find(array_from_s[leftIndex]) == std::string::npos)
				{
					leftIndex ++;
				}
				while (leftIndex < rightIndex && string_vowels.find(array_from_s[rightIndex]) == std::string:: npos)
				{
					rightIndex--;
				}
				std::swap(array_from_s[leftIndex++], array_from_s[rightIndex--]);
			}
			return std::string (array_from_s.begin(), array_from_s.end());
		}
};

int main ()
{
	Solution sol;
	std::string input_string = "hello";
	std:: string expected_output_string = "yasser";
	std:: string actual_output_string = sol.reverse_vowels(input_string);
	std::cout << "OUTPUT: " << (actual_output_string == expected_output_string) << std::endl;
}
