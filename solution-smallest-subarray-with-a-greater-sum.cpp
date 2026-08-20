using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMinSubArray(int S, const vector<int>& arr) 
    {
       int startIndex = 0;
       int windowSum = 0;
       int minlength = arr.size() + 1 ;
       for(int endIndex = 0; endIndex < arr.size(); endIndex ++)
       {
         windowSum += arr[endIndex];
         while(windowSum >= S)
         {
            minlength = min(minlength, endIndex - startIndex +1);
            windowSum -= arr[startIndex ++];
         }
       } 
       if(minlength >= arr.size())
       {
         minlength = 0;
       }
      return minlength;
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
    result = sol.findMinSubArray(10, vector<int>{1, 1, 1});
    cout << "Smallest subarray length: " << result << endl;
}

