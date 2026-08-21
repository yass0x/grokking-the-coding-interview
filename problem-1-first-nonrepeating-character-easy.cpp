#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // ToDo: Write Your Code Here.
        return -1;
    }
};
int main() {
    Solution sol;
    cout << sol.firstUniqChar("apple") << endl;  // Expected: 0
    cout << sol.firstUniqChar("abcab") << endl;  // Expected: 2
    cout << sol.firstUniqChar("abab") << endl;   // Expected: -1
}