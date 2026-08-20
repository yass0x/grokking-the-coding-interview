#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_openParentheses;
        for (int  i = 0; i < s.length(); i++)
        {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    stack_openParentheses.push(s[i]);
                }
                else
                {
                    switch (stack_openParentheses.top())
                    {
                    case '(':
                        /* code */
                        if (s[i] == ')')
                        {
                            stack_openParentheses.pop();
                        }
                        else
                        {
                            return false;
                        }
                        
                        break;
                    case '{':
                        /* code */
                        if (s[i] == '}')
                        {
                            stack_openParentheses.pop();
                        }
                        else
                        {
                            return false;
                        }
                        
                        break;
                    case '[':
                        /* code */
                        if (s[i] == ']')
                        {
                            stack_openParentheses.pop();
                        }
                        else
                        {
                            return false;
                        }
                        
                        break;
                    
                    default:
                        return false;
                        break;
                    }
                }
        }
          
        return stack_openParentheses.empty();
    }
};


int main() {
    Solution sol;

    string test1 = "{[()]}"; // Should be valid
    string test2 = "{[}]";   // Should be invalid
    string test3 = "(]";     // Should be invalid
    
    cout << "Test 1: " << sol.isValid(test1) << endl;
    cout << "Test 2: " << sol.isValid(test2) << endl;
    cout << "Test 3: " << sol.isValid(test3) << endl;

    return 0;
}
