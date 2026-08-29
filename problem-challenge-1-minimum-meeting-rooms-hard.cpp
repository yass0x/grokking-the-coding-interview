
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:

  int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    int minRooms = 1;
    // TODO: Write your code here
    sort(meetings.begin(), meetings.end(), customCompareFunc);

    Meeting firstEndingMeeting = meetings[0];
    for (int i = 1; i < meetings.size(); i++)
    {
        /* code */
        if (meetings[i].start < firstEndingMeeting.end)
        {
            minRooms++;
            if(meetings[i].end < firstEndingMeeting.end)
            {
               firstEndingMeeting = meetings[i];
            }
        }
        else
        {
            firstEndingMeeting = meetings[i];
        }

    }
    
    return minRooms;
  }
private:
  static bool customCompareFunc(Meeting a, Meeting b)
  {
    return a.start < b.start;
  }
  static bool customCompareFunc2(const Meeting a, const Meeting b)
  {
     return a.end < b.end;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<Meeting> input = {{1, 4}, {2, 5}, {7, 9}};
  int result = sol.findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = sol.findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = sol.findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = sol.findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 3}, {3, 5}, {4, 7}};
  result = sol.findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}
