#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
string decimalToBinary(int num) {
    // ToDo: Write Your Code Here.
    stack<char> stack_binaryForm;
    string ret_string;
    while (num != 0)
    {
        stack_binaryForm.push('0'+ num%2);
        num /=2;
    }

    int stackSize = stack_binaryForm.size();
    for (int i = 0; i < stackSize; i++)
    {
            ret_string.push_back(stack_binaryForm.top());
            stack_binaryForm.pop();
    }
    
        return ret_string;
}
};

int main() {
    Solution sol;
    cout << sol.decimalToBinary(2) << endl;  // Output: 10 (Binary representation of decimal 2)
    cout << sol.decimalToBinary(7) << endl;  // Output: 111 (Binary representation of decimal 7)
    cout << sol.decimalToBinary(18) << endl; // Output: 10010 (Binary representation of decimal 18)
    return 0;
}
