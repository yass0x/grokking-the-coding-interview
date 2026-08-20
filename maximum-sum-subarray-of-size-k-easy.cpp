using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMaxSumSubArray(int k, const vector<int>& arr) {
      int maxSum = 0;
      // TODO: Write your code here
      int leftIdx = 0;
      int endIdx = 0;
      int windowSum=0;
      for (endIdx = 0; endIdx < arr.size(); endIdx++)
      {
        windowSum += arr[endIdx];
        if (endIdx >= k - 1)
        {
          maxSum = max(maxSum, windowSum);
          windowSum -= arr[leftIdx];
          leftIdx ++;            
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