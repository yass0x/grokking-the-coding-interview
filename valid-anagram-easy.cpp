# include <iostream>
#include <vector>
# include <algorithm>
class Solution
{
	public:
		bool isAnagram(std::string s, std::string t)
		{
			std::vector<char> array_from_string_s(s.begin(), s.end());
			std:: vector <char> array_from_string_t(t.begin(), t.end());
			std::sort(array_from_string_s.begin(), array_from_string_s.end());
			std::sort(array_from_string_t.begin(), array_from_string_t.end());
			if(array_from_string_s == array_from_string_t)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

int main ()
{
	Solution sol;
	std::string input_string1 = "listen";
	std::string input_string2 = "sasfaafadf";
	std::cout << "OUTPUT: " << sol.isAnagram(input_string1, input_string2) << std::endl;
}
