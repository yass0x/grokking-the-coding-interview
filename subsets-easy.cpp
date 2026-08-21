using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());
    // TODO: Write your code here
    for (int  i = 0; i < nums.size(); i++)
    {
        int subsetsCurrentSize = subsets.size();
        for (int j = 0; j < subsetsCurrentSize; j++)
        {
            subsets.push_back(subsets[j]);
            subsets.back().push_back(nums[i]);
        }   
    }
    
    return subsets;
  }
};   

int main(int argc, char* argv[]) {
  Solution sol;
  vector<vector<int>> result = sol.findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = sol.findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
