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
  ListNode *findCycleStart(ListNode *head) {
    // TODO: Write your code here
    ListNode *fastPtr = head;
    ListNode *slowPtr = head;
    while (fastPtr ->next != nullptr && fastPtr -> next -> next != nullptr)
    {
        fastPtr = fastPtr ->next -> next;
        slowPtr = slowPtr ->next ;
        if (slowPtr == fastPtr)
        {
            break;
        }
    }

    ListNode *startPtr = head;
    while ( startPtr != slowPtr)
    {
        fastPtr = slowPtr ->next;
        while (fastPtr != slowPtr)
        {
            if (fastPtr == startPtr)
            {
                return startPtr;
            }
            fastPtr = fastPtr ->next;
        }
        startPtr = startPtr -> next;
    } 
    startPtr = slowPtr;
    return startPtr;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  // Create a cycle by connecting nodes
  /*head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " 
      << sol.findCycleStart(head)->val << endl;*/

  // Create a different cycle
  /*head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " 
      << sol.findCycleStart(head)->val << endl;*/

  // Create a cycle that points back to the head
 head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " 
      << sol.findCycleStart(head)->val << endl; 
}

