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
  bool hasCycle(ListNode *head) {
    // TODO: Write your code here
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;
    while (fastPtr->next !=nullptr && fastPtr->next->next !=nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr =fastPtr -> next -> next;
        if(slowPtr == fastPtr)
        {
            return true;
        }
    }
    return false;
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
  cout << "LinkedList has cycle: " << sol.hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next; // Create a cycle by connecting the last node to the third node
  cout << "LinkedList has cycle: " << sol.hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next->next; // Create a cycle by connecting the last node to the fourth node
  cout << "LinkedList has cycle: " << sol.hasCycle(head) << endl;
}
