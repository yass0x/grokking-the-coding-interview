using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int searchTriplet(vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    return 0;
  }
};

int main(int argc, char* argv[]) {
  Solution sol;
  vector<int> vec = {-1, 0, 2, 3};
  cout << sol.searchTriplet(vec, 2) << endl;
  vec = {-3, -1, 1, 2};
  cout << sol.searchTriplet(vec, 1) << endl;
  vec = {1, 0, 1, 1};
  cout << sol.searchTriplet(vec, 100) << endl;
  vec = {0, 0, 1, 1, 2, 6};
  cout << sol.searchTriplet(vec, 5) << endl;
}