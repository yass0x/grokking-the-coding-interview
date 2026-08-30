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
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    int cycleLenght = findCycleLenght(slowPtr, fastPtr);

    return findCycleStart(head, cycleLenght);
  }

private: 

  static int findCycleLenght(ListNode *slowPtr, ListNode *fastPtr)
  {
    while (slowPtr != fastPtr)
    {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }

    int cycleLenght = 1;
    fastPtr = fastPtr ->next;
    while (slowPtr != fastPtr)
    {
        cycleLenght++;
        fastPtr = fastPtr -> next;
    }
    return cycleLenght;
  }
  static ListNode* findCycleStart (ListNode *head, int cycleLenght)
  {
    ListNode *cycleStartNode = head;
    ListNode *nodeComparator = head;
    
    while (cycleLenght != 0)
    {
        /* code */
        nodeComparator = nodeComparator ->next;
        cycleLenght--;
    }

    while (nodeComparator != cycleStartNode)
    {
        /* code */
        nodeComparator = nodeComparator -> next;
        cycleStartNode = cycleStartNode -> next;
    }

    return cycleStartNode;
    
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

