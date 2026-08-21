using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>


class Solution
{
public:
    int findLength(const string &str, int k)
    {
        int windowStart = 0, maxLength = 0;
        // TODO: Write your code here
        unordered_map<char, int> char_freq;

        for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
        {


             char_freq[static_cast<char> (str[windowEnd])] ++;    

            while (char_freq.size() > k )
                {
                    char_freq[static_cast<char> (str[windowStart])]--;
                    
                    if(char_freq[static_cast<char> (str[windowStart])] == 0)
                    {
                        char_freq.erase(str[windowStart]); 
                    }
                    windowStart++;
                }
            maxLength = max(maxLength, windowEnd - windowStart + 1);         
        }
        
        return maxLength;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << "Length of the longest substring: "
        << sol.findLength("araaci", 2) << endl;
    cout << "Length of the longest substring: "
        << sol.findLength("araaci", 1) << endl;
    cout << "Length of the longest substring: "
        << sol.findLength("cbbebi", 3) << endl;
        cout << "Length of the longest substring: "
        << sol.findLength("aabbccdd", 2) << endl;
}
