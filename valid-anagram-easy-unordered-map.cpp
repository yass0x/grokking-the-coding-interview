# include <iostream>
#include <unordered_map>

class Solution
{
	public: 
		bool isAnagram(std::string s, std::string t)
		{
			if(s.length() != t.length())
			{
				return false;
			}
			std::unordered_map<char, int> char_freq;
			for (int i = 0; i< s.length(); i++)
			{
				char_freq[s[i]]++;
				char_freq[t[i]]--;
			}

			for (const auto& [key, freq] : char_freq)
			{
				if (freq !=0 )
				{
					return false;
				}
			}
			return true;
		}
};


int main ()
{
	Solution sol;
	std::string s1 = "listen";
	std::string s2 = "silent";
	std::cout << "OUTPUT: " << sol.isAnagram(s1, s2) << std::endl;
}
