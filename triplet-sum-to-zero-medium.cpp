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

    int leftIdx = 0;
    int rightIdx = arr.size() -1;
    int thirdElement = 0;
    int i = 0;

    while (leftIdx < rightIdx)
    {
        /* code */
        if (arr[leftIdx] + arr[rightIdx] < 0)
        {
            if(arr[leftIdx] + arr[rightIdx] + arr[rightIdx-1] == 0)
            {
                triplets[i] = {arr[leftIdx], arr[rightIdx], arr[rightIdx-1]};
                i++;

            }
            leftIdx ++;
        }
        if (arr[leftIdx] + arr[rightIdx] > 0)
        {
            if(arr[rightIdx] + arr[leftIdx] + arr[leftIdx+1] == 0)
            {
                triplets[i] = {arr[leftIdx], arr[rightIdx], arr[rightIdx+1]};
                i++;
                leftIdx ++;
                rightIdx +=2;
            }
            else
            {
                leftIdx ++;
                            
            }           
        }
    }
    
    return triplets;
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
