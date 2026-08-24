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
    int minSum = std::numeric_limits<int>::max();

    for (int  i = 0; i < arr.size() -2; i++)
    {
        if (arr[i] > 0 && arr[i] == arr[i-1])
        {
            continue;
        } 
        int currentMinSum = findCurrentMinClosestSumToTarget(arr, (targetSum - arr[i]), i + 1);
        minSum = min(minSum, targetSum - currentMinSum - arr[i]); 
    }
    
    return targetSum - minSum;
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
            minDiff = (minDiff, Sum - currentSum);
            leftIdx++;
            while (leftIdx < rightIdx && arr[leftIdx] == arr[leftIdx -1])
            {
                leftIdx++;
            }
            
        }
        else if(Sum < currentSum)
        {
            minDiff = (minDiff, currentSum- Sum);
            rightIdx--;
            while (leftIdx < rightIdx && arr[rightIdx] == arr[rightIdx+1])
            {
                rightIdx--;
            }
            
        }
        else
        {
            minDiff = 0;
            break;
        }
    }   
    return minDiff;
  }
};

int main(int argc, char* argv[]) {
  Solution sol;
  vector<int> vec = {-1, 0, 2, 3};
  cout << sol.searchTriplet(vec, 3) << endl;
  vec = {-3, -1, 1, 2};
  cout << sol.searchTriplet(vec, 1) << endl;
  vec = {1, 0, 1, 1};
  cout << sol.searchTriplet(vec, 100) << endl;
  vec = {0, 0, 1, 1, 2, 6};
  cout << sol.searchTriplet(vec, 5) << endl;
}