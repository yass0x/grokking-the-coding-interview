using namespace std;

#include <iostream>
#include <vector>

class Interval {
public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  vector<Interval> merge(const vector<Interval> &arr1, 
                                const vector<Interval> &arr2) {
    vector<Interval> result;
    // TODO: Write your code here
    
    for (int  j = 0; j < arr2.size(); j++)
    {
       int i = 0; 
        while(i < arr1.size() && arr1[i].start <= arr2[j].end)
        {
            if (arr1[i].end >= arr2[j].start)
            {
                Interval currentInterval = {max(arr1[i].start, arr2[j].start), min(arr1[i].end, arr2[j].end)};
                result.push_back(currentInterval);
            }
            i++;
        }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<Interval> input1 = {{1, 3}, {5, 6}, {7, 9}};
  vector<Interval> input2 = {{2, 3}, {5, 7}};
  vector<Interval> result = sol.merge(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input1 = {{1, 3}, {5, 7}, {9, 12}};
  input2 = {{5, 10}};
  result = sol.merge(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
}

