using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int searchTriplet(vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    int Diff = std::numeric_limits<int>::max();

    for (int  i = 0; i < arr.size() -2; i++)
    {

        int currentPointersSum = findCurrentMinClosestSumToTarget(arr, (targetSum - arr[i]), i + 1);
        if (targetSum - currentPointersSum - arr[i] > 0)

        Diff = min(Diff, targetSum - currentPointersSum - arr[i]);   
    }
    
    return targetSum - Diff;
  }

  private:
   static int findCurrentMinClosestSumToTarget(vector<int> arr, int Sum, int leftIdx)
  {
    int rightIdx = arr.size() - 1;

    int minDiff = std::numeric_limits<int>::max();
    while (leftIdx < rightIdx)  
    {
        int currentSum = arr[leftIdx] + arr[rightIdx];
        if (Sum > currentSum)
        {
            minDiff = min(minDiff, Sum - currentSum);
            leftIdx++;

            
        }
        else if(Sum < currentSum)
        {
            minDiff = min(minDiff, currentSum- Sum);
            rightIdx--;

            
        }
        else
        {
            minDiff = 0;
            break;
        }
    }   
    return Sum - minDiff;
  }
};

int main(int argc, char* argv[]) {
  Solution sol;
  vector<int> vec = {39, -55, 11, 69, 4, -9, 6, 23};
  cout << sol.searchTriplet(vec, -72) << endl;
  vec = {-3, -1, 1, 2};
  cout << sol.searchTriplet(vec, 1) << endl;
  vec = {1, 0, 1, 1};
  cout << sol.searchTriplet(vec, 100) << endl;
  vec = {0, 0, 1, 1, 2, 6};
  cout << sol.searchTriplet(vec, 5) << endl;
}