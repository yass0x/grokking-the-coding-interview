#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <unordered_map>

using namespace std;

class Solution {
	public:
		int shortestDistance(vector<string>& words, string word1, string word2) {
			
			int shortestDistance = words.size();
			int word1_index = -1, word2_index = -1;
			for (int i = 0; i < words.size(); i++)
			{
				if ( words[i] == word1)
				{
					word1_index = i;
				}
				else if (words[i] == word2)
				{
					word2_index = i;
				}
				else
				{

				}
				if (word1_index >=0 && word2_index >= 0)
				{
					if ((word1_index > word2_index) && (shortestDistance > (word1_index - word2_index)))
					{
						shortestDistance = word1_index - word2_index;
					}
					else if((word2_index > word1_index) && (shortestDistance > (word2_index - word1_index)))
					{
						shortestDistance = word2_index - word1_index;
					}
				}
			}
			return shortestDistance;
		}
};

int main ()
{
	Solution sol;
	std::vector<string> words_vector = {"the","quick","brown","fox","jumps","over","the","lazy","dog"};
	std::string word1 = "fox";
	std::string word2 = "dog";
	std::cout << "OUTPUT: " << sol.shortestDistance( words_vector, word1, word2) << std::endl;
}





