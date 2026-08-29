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
  vector<Interval> insert(const vector<Interval> &intervals, 
                                Interval newInterval) {
    vector<Interval> mergedIntervals;
    // TODO: Write your code here
    int i = 0;
    while (i < intervals.size() && intervals[i].end < newInterval.start)
    {
        /* code */
        mergedIntervals.push_back(intervals[i]);
        i++;
    }

    Interval currentInterval = newInterval;
    while (i < intervals.size() && intervals[i].start <= currentInterval.end )
    {
        currentInterval.start = min(currentInterval.start, intervals[i].start);
        currentInterval.end = max(currentInterval.end, intervals[i].end);      
        i++;
    }
    mergedIntervals.push_back(currentInterval);
    
    while (i < intervals.size())
    {
        mergedIntervals.push_back(intervals[i]);
        i++;
    }   
    return mergedIntervals;
  }

};


int main(int argc, char *argv[]) {
  Solution sol;
  vector<Interval> input = {{1, 2}, {3, 4}, {5, 6}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : sol.insert(input, {2, 5})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals after inserting the new interval: ";
  for (auto interval : sol.insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : sol.insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
