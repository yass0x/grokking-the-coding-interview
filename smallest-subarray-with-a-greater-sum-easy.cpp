using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMinSubArray(int S, const vector<int>& arr) 
    {
      for (int i = 1; i <= arr.size(); i ++)
      {
        int startIndex = 0;
        int windowSum = 0;
        int maxWindowSum = 0;
        for (int endIndex = 0; endIndex < arr.size(); endIndex++)
        {
            windowSum += arr[endIndex];
            if (endIndex >= i-1)
            {
                maxWindowSum = max(maxWindowSum, windowSum);
                windowSum -= arr[startIndex++];

            }
        }

        if(maxWindowSum >= S)
        {
                return i;
        }

      }
      return 0;
    }
  };

  int main(int argc, char *argv[])
{
    Solution sol;
    int result = sol.findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
    cout << "Smallest subarray length: " << result << endl;
    result = sol.findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
    cout << "Smallest subarray length: " << result << endl;
    result = sol.findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
    cout << "Smallest subarray length: " << result << endl;
}

