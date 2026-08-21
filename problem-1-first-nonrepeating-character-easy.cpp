#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // ToDo: Write Your Code Here.
        unordered_map<char, int> charFreqMap;
        int firstNonRepeatingCharIdx = -1;
        for (int i = 0; i < s.length(); i++)
        {
            charFreqMap[s[i]] ++;
        }
        for (int  i = 0; i < s.length(); i++)
        {
            if(charFreqMap[s[i]] == 1)
            {
               firstNonRepeatingCharIdx = i; 
               break;
            } 
        }
        

        return firstNonRepeatingCharIdx;
    }
};
int main() {
    Solution sol;
    cout << sol.firstUniqChar("apple") << endl;  // Expected: 0
    cout << sol.firstUniqChar("abcab") << endl;  // Expected: 2
    cout << sol.firstUniqChar("abab") << endl;   // Expected: -1
    cout << sol.firstUniqChar("swiss") << endl;   // Expected: 1
}