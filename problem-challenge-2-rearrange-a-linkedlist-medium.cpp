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
  ListNode* reorder(ListNode *head) {
    // TODO: Write your code here

    ListNode *midPoint = head;

    /* find midPoint */
    findMidPoint(head, midPoint);

    /* Reverse the Second Half */
    reverseLinkedList(midPoint);

    ListNode *travesePtr = head;
    ListNode *currentNode = midPoint;
    while (travesePtr != nullptr && travesePtr -> next != nullptr)
    {
         removeNode(midPoint, currentNode);
         insertNode(travesePtr, currentNode);
         travesePtr = travesePtr -> next -> next;
    }
    return head;
  }
private:
  static void findMidPoint(ListNode* &head, ListNode* &slowPtr)
  {
    ListNode *fastPtr = head;
    while (fastPtr !=nullptr && fastPtr -> next != nullptr)
    {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }
  }
  static void reverseLinkedList(ListNode *head)
  {
    ListNode *Previous = nullptr;
    ListNode *next = head -> next;
    while (next != nullptr)
    {
        head -> next = Previous;
        Previous = head;
        head = next;
        next = next -> next;
    }
    head -> next = Previous;
  }
  static void insertNode(ListNode * &head, ListNode * &newNode)
  {
    ListNode *temp = head ->next;
    head -> next = newNode;
    newNode ->next = temp;
  }
  static void removeNode(ListNode * &head, ListNode* &removedNode)
  {
    removedNode = head;
    removedNode -> next = nullptr;
    head = head -> next;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(6); 
  head->next->next->next ->next  = new ListNode(4);
  head->next->next->next->next ->next = new ListNode(5);
  cout << "Is palindrome: " << sol.reorder(head) << endl;
}
