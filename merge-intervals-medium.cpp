using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

/*class Interval {
public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};*/

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> mergedIntervals;
    // TODO: Write your code here
    return mergedIntervals;
  }
};


int main(int argc, char *argv[]) {
  Solution sol;
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : sol.merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : sol.merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : sol.merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
