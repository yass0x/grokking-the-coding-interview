using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
  int start;
  int end;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  bool canAttendAllAppointments(vector<Interval>& intervals) {
    // TODO: Write your code here
    sort(intervals.begin(), intervals.end(), customCompareFunc);
    Interval currentInterval = intervals[0];
    for (int  i = 1; i < intervals.size(); i++)
    {
        if (currentInterval.end > intervals[i].start)
        {
            return false;
        }
        else
        {
            currentInterval = intervals[i];
        }
        
    }
    
    return true;
  }
private:
  static bool customCompareFunc(Interval a, Interval b)
  {
    return a.start < b.start;
  }
};

int main(int argc, char* argv[]) {
  Solution sol;
  vector<Interval> intervals = {{1, 4}, {2, 5}, {7, 9}};
  bool result = sol.canAttendAllAppointments(intervals);
  cout << "Can attend all appointments: " << result << endl;

  intervals = {{6, 7}, {2, 4}, {8, 12}};
  result = sol.canAttendAllAppointments(intervals);
  cout << "Can attend all appointments: " << result << endl;

  intervals = {{4, 5}, {2, 3}, {3, 6}};
  result = sol.canAttendAllAppointments(intervals);
  cout << "Can attend all appointments: " << result << endl;
}
