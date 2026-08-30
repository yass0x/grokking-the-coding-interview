using namespace std;
#include <iostream>


class Solution {
public:
  bool find(int num) {
    // TODO: Write your code here
    nextNum(num);

    int slow = num;
    int fast = num;
    int *slowPtr = &slow;
    int *fastPtr = &fast;

    while (nextNum(*fastPtr) != 1 && nextNum(nextNum(*fastPtr)) != 1)
    {
        *slowPtr = nextNum(*slowPtr);
        *fastPtr = nextNum(nextNum(*fastPtr));
        if (*slowPtr == *fastPtr )
        {
            return false;
        }
    }
    
    return true;
  }

private:
    static int nextNum(int num)
    {
        int sum = 0;
        while (num !=0)
        {
            sum += ((num%10) * (num%10));
            num /= 10;
        }
        return sum;
    }
};

int main ()
{
    Solution sol;
    int num = 4535;
    cout << num << " is happy number? " << sol.find(num) << endl;

    num = 12;
    cout << num << " is happy number? " << sol.find(num) << endl;

    num = 1;
    cout << num << " is happy number? " << sol.find(num) << endl;
}

