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
  ListNode *findMiddle(ListNode *head) {
    // TODO: Write your code here

    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (fastPtr -> next != nullptr && fastPtr ->next ->next !=nullptr)
    {
        slowPtr = slowPtr ->next ;
        fastPtr = fastPtr -> next ->next;
    }
    if (fastPtr -> next == nullptr)
    {
        return slowPtr;
    }
    else
    {
        return slowPtr->next;
    }
    
    return head;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "Middle Node: " << sol.findMiddle(head)->val << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "Middle Node: " << sol.findMiddle(head)->val << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Middle Node: " << sol.findMiddle(head)->val << endl;
}