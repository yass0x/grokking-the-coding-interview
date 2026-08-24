using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    std::sort(arr.begin(), arr.end());
    for (int  i = 0; i < arr.size() -2; i++)
    {
      if (i > 0 && arr[i] != arr[i+1])
      {
        continue;;
      }
      searchPair(arr, -arr[i], i + 1, triplets);
      
    } 
    
    return triplets;
  }
private:
  static void searchPair(vector<int> arr, int targetSum, int leftIdx, vector<vector<int>> triplets)
  {
    int rightIdx = arr.size() - 1;
    while (leftIdx < rightIdx)
    {
      int currentSum = arr[leftIdx] + arr[rightIdx];
      if(currentSum == targetSum)
      {
        triplets.push_back({-targetSum, arr[leftIdx], arr[rightIdx]});
        leftIdx++;
        rightIdx--;
        while (leftIdx < rightIdx && arr[leftIdx] == arr[leftIdx -1])
        {
          leftIdx++;
        }
        while (leftIdx < rightIdx && arr[rightIdx] == arr[rightIdx +1])
        {
          rightIdx--;
        }     
      }
      else if(currentSum > targetSum)
      {
        rightIdx--;
      }
      else
      {
        leftIdx++;
      }
    }
    
  }
};


int main(int argc, char *argv[]) {
  Solution sol;
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
  auto result = sol.searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {-5, 2, -1, -2, 3};
  result = sol.searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
