using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    int findLength(const vector<char> &arr)
    {
        int maxLength = 0;
        // TODO: Write your code here
        int startIdx = 0;
        unordered_map<char, int> charFrequencyMap;
        for (int endIdx = 0; endIdx < arr.size(); endIdx++)
        {
            charFrequencyMap[arr[endIdx]]++;
            while (charFrequencyMap.size() > 2)
            {
                charFrequencyMap[arr[startIdx]]--;
                
                if (charFrequencyMap[arr[startIdx]] == 0)
                {
                    charFrequencyMap.erase(arr[startIdx]);
                }
                startIdx++;
            }
            maxLength = max(maxLength, endIdx - startIdx +1);
        }
        

        return maxLength;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << "Maximum number of fruits: "
        << sol.findLength(vector<char>{'A', 'B', 'C', 'A', 'C'})
        << endl;
    cout << "Maximum number of fruits: "
        << sol.findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'})
        << endl;
}
