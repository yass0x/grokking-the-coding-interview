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
    /* Solution 2: solve using reverseing the linked list */

    bool retVal = true;

    /* Find the mid-point */
    ListNode *midPoint = findMidPoint(head); 
    

    /* Reverse Second Half */
    ReverseLinkedList(midPoint);

    ListNode *SecondhalfStart = midPoint ;
    ListNode *FirsthalfStart = head;

    /* Compare the two halves */
    while (FirsthalfStart != nullptr && SecondhalfStart != nullptr)
    {
        if (FirsthalfStart -> val != SecondhalfStart -> val)
        {
            retVal = false;
            break;
        }  
        FirsthalfStart = FirsthalfStart -> next;
        SecondhalfStart = SecondhalfStart -> next; 
    }
    /* Revert back the change */
    ReverseLinkedList(midPoint);
    return retVal;
  }
private: 
  static ListNode* findMidPoint(ListNode *head)
  {
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;
    while (fastPtr != nullptr && fastPtr -> next != nullptr)
    {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }
    return slowPtr;
  }

  static void ReverseLinkedList(ListNode* &head)
  {
    ListNode *prev = nullptr;
    ListNode *next = head -> next;

    while (next != nullptr)
    {
        head -> next = prev;
        prev = head;
        head = next;
        next = next -> next;
    }
    head -> next = prev;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  ListNode *head = new ListNode(2);
  /* cout << sizeof(int) << endl; */
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  /* head->next->next->next = new ListNode(6); */
  head->next->next->next/* ->next */ = new ListNode(4);
  head->next->next->next->next /* ->next */ = new ListNode(5);
  cout << "Is palindrome: " << sol.isPalindrome(head) << endl;

 /*head->next->next->next->next->next = new ListNode(5);
  cout << "Is palindrome: " << sol.isPalindrome(head) << endl; */
}

