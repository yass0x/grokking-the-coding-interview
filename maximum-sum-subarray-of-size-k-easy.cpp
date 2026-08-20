using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMaxSumSubArray(int k, const vector<int>& arr) 
    {
        int windowSum = 0;
        int maxSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < findMaxSumSubArray.size() -1; windowEnd++)
        {
            windowSum += arr[windowEnd];
            if( windowEnd >= k - 1)
            {
                maxSum = max(maxSum, windowStart);
                windowSum -= arr[windowStart++];
            }
        }
        return maxSum;
    }
  };        

  int main(int argc, char *argv[])
{
    Solution sol;
    cout << "Maximum sum of a subarray of size K: "
        << sol.findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2})
        << endl;
    cout << "Maximum sum of a subarray of size K: "
        << sol.findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5})
        << endl;
    cout << "Maximum sum of a subarray of size K: "
        << sol.findMaxSumSubArray(1, vector<int>{1, 2, 3, 4, 5})
        << endl;
}