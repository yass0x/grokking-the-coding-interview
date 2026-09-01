using namespace std;

#include <iostream>

class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    // TODO: Write your code here
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (fastPtr -> next != nullptr && fastPtr ->next -> next != nullptr)
    {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }

    ListNode *firstHalf = head;
    ListNode *secodnHalf = slowPtr ->next ;
    int OperationFirstHalf = 0;
    int OperationSecondHalf = 0;
    int multiplier = 1;

    if(fastPtr ->next == nullptr)
    {
        while (firstHalf != slowPtr)
        {
            OperationFirstHalf += (firstHalf->val * multiplier);
            multiplier *= 10;
            firstHalf = firstHalf -> next; 
        }
        multiplier /= 10;
        while (secodnHalf != nullptr)
        {
            OperationSecondHalf += (secodnHalf -> val * multiplier);
            multiplier /= 10;
            secodnHalf = secodnHalf ->next;
        }

        if (OperationFirstHalf == OperationSecondHalf)
        {
            return true;
        }
        
    }
    else
    {
        while (firstHalf != slowPtr -> next)
        {
            OperationFirstHalf += (firstHalf->val * multiplier);
            multiplier *= 10;
            firstHalf = firstHalf -> next; 
        }
        multiplier /= 10;
        while (secodnHalf != nullptr)
        {
            OperationSecondHalf += (secodnHalf -> val * multiplier);
            multiplier /= 10;
            secodnHalf = secodnHalf ->next;
        }

        if (OperationFirstHalf == OperationSecondHalf)
        {
            return true;
        }
    }
    
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  ListNode *head = new ListNode(2);
  /* cout << sizeof(int) << endl; */
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(6);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << sol.isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(5);
  cout << "Is palindrome: " << sol.isPalindrome(head) << endl;
}

