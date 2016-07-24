#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if ( l1 == NULL )
    return l2;
    else 
    return l1;

    ListNode* ptr1 = l1;
    ListNode* ptr2 = l2;
    ListNode* newList;
    ListNode* newPtr;

    newList = newPtr;
    while( ptr1 != NULL && ptr2 != NULL )
    {
      if ( ptr1->val > ptr2->val )
      {
        newPtr->next = ptr2;
        newPtr = ptr2;
        ptr2 = ptr2->next;
        (*newPtr).next = NULL;
      }
      else
      {
        newPtr->next = ptr1;
        newPtr = ptr1;
        ptr1 = ptr1->next;
        (*newPtr).next = NULL;
      }
    }

    if ( ptr1 == NULL )
      (*newPtr).next = ptr2;
    else
      (*newPtr).next = ptr1;

    return newList;
  }
};