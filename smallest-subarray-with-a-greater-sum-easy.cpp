using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMinSubArray(int S, const vector<int>& arr) {
      // TODO: Write your code here
      int arrLength = arr.size() + 1;
      int firstIndx = 0;
      int windowSum = 0;
      for(int endIdx = 0; endIdx < arr.size(); endIdx++)
      {
        windowSum+= arr[endIdx];
        while( windowSum >= S)
        {
          arrLength = min(arrLength, endIdx - firstIndx + 1);
          windowSum -= arr[firstIndx];
          firstIndx++;
        }
      }

      return arrLength == arr.size()+1 ? 0 : arrLength;
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
    result = sol.findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
    cout << "Smallest subarray length: " << result << endl;
}

