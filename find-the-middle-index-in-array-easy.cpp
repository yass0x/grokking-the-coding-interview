#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // ToDo: Write Your Code Here
        vector<int> numSum;
        numSum[0] = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            numSum[i+1] = numSum [i] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            if (numSum[nums.size()]- numSum[i] == numSum[i])
            {
                return i;
            }
            
        }
        return -1; 
    }


    
};

