#include "iostream"
#include "limits.h"

using namespace std;
/**
* Definition for singly-linked list.
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class LiskListSolution {
public:
  void deleteNode(ListNode *prev, ListNode *pToDel) {
    if (!prev || !pToDel) {
      return;
    }
    if (prev->next != pToDel)
      return;
    if (pToDel->next != NULL) {
      prev->next = pToDel->next;
    }

    delete pToDel;
  }
  void popNode(ListNode *prev, ListNode *pToPop) {
    if (!prev || !pToPop) {
      return;
    }
    if (prev->next != pToPop)
      return;
    if (pToPop->next != NULL) {
      prev->next = pToPop->next;
    }
  }
  void insertNode(ListNode *prev, ListNode *pToInsert) {
    if (!prev || !pToInsert) {
      return;
    }
    ListNode *tmp;
    tmp = prev->next;
    prev->next = pToInsert;
    pToInsert->next = tmp;
  }

  // ListNode *sortList(ListNode *head) {
  //   ListNode *dummy = new ListNode(0);
  //   dummy->next = head;
  //   ListNode *pnode = dummy;
  //   int node_val;
  //
  //   // pnode = pnode->next;
  //
  //   while (pnode) {
  //     ListNode *qnode = pnode->next;
  //     node_val = pnode->next->val;
  //     while (qnode->next) {
  //       if (node_val > qnode->next->val) {
  //         ListNode *tmp;
  //         tmp = qnode->next;
  //         popNode(qnode, qnode->next);
  //         insertNode(pnode, tmp);
  //       }
  //       qnode = qnode->next;
  //     }
  //     pnode = pnode->next;
  //   }
  //   return dummy->next;
  // }

  ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return head;
    //
    ListNode *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    //
    fast = slow;
    slow = slow->next;
    fast->next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    return mergeTwoLists(l1, l2);
    //
    //
  }
  // Merge Two Sorted Lists
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    for (ListNode *p = &dummy; l1 != NULL || l2 != NULL; p = p->next) {
      int val1 = l1 == NULL ? INT_MAX : l1->val;
      int val2 = l2 == NULL ? INT_MAX : l2->val;
      if (val1 <= val2) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
    }
    return dummy.next;
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unsigned int length1 = traversal(headA);
    unsigned int length2 = traversal(headB);
    ListNode *pShortNode, *pLongNode;
    unsigned int diff_len;
    if (length1 < length2) {
      pShortNode = headA;
      pLongNode = headB;
      diff_len = length2 - length1;
    } else {
      pShortNode = headB;
      pLongNode = headA;
      diff_len = length1 - length2;
    }
    for (size_t i = 0; i < diff_len; i++) {
      pLongNode = pLongNode->next;
    }
    while (pLongNode && pShortNode && pLongNode != pShortNode) {
      pLongNode = pLongNode->next;
      pShortNode = pShortNode->next;
    }
    return pLongNode;
  }
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        ListNode *slow2 = head;
        while (slow2 != slow) {
          slow2 = slow2->next;
          slow = slow->next;
        }
        return slow2;
      }
    }
    return NULL;
  }
  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }

  ListNode *reverseBetween2(ListNode *head, int m, int n) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *prev = &dummy;
    for (int i = 0; i < m - 1; ++i)
      prev = prev->next;
    ListNode *const head2 = prev;
    prev = head2->next;
    ListNode *cur = prev->next;
    for (int i = m; i < n; ++i) {
      prev->next = cur->next;
      cur->next = head2->next;
      head2->next = cur;
      cur = prev->next;
    }
    return dummy.next;
  }
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head)
      return head;

    if (m == n) {
      return head;
    }
    ListNode *next_node;
    ListNode *cur_node = head;
    ListNode *prev_node = head;
    prev_node = head;
    ListNode *start_node = head->next;
    ListNode *end_node = head;
    int node_idx = 1;
    while (cur_node) {
      if (node_idx < m) {
        prev_node = cur_node;
        cur_node = cur_node->next;
      } else if (node_idx == m) {
        end_node = prev_node;
        start_node = cur_node;
        cur_node = cur_node->next;
      } else if (node_idx < n) {
        next_node = cur_node->next;
        cur_node->next = prev_node;
        prev_node = cur_node;
        cur_node = next_node;
      } else if (node_idx == n) {
        start_node->next = next_node = cur_node->next;
        cur_node->next = prev_node;
        end_node->next = cur_node;
        if (m == 1) {
          head->next = NULL;
          head = cur_node;
        }
        cur_node = next_node;
      }
      node_idx++;
    }

    return head;
  }
  int traversal(ListNode *head) {
    ListNode *pn = head;
    int node_num = 0;
    while (pn != NULL) {
      node_num++;
      pn = pn->next;
    }
    return node_num;
  }
  void printall(ListNode *head) {
    ListNode *pn = head;
    while (pn != NULL) {
      std::cout << pn->val << '\t';
      pn = pn->next;
    }
  }
};

int main(int argc, char const *argv[]) {

  ListNode *head = new ListNode(-1);
  ListNode *pre_node = head;
  ListNode *end_node1, *end_node2;

  for (int i = 40; i < 43; i++) {
    ListNode *node = new ListNode(i);
    pre_node->next = node;
    pre_node = node;
  }
  end_node1 = pre_node;
  // pre_node->next = head;
  ListNode *head2 = new ListNode(0);

  pre_node = head2;
  for (int i = 10; i < 13; i++) {
    ListNode *node = new ListNode(i);
    pre_node->next = node;
    pre_node = node;
  }
  end_node2 = pre_node;

  ListNode *head3 = new ListNode(-1);

  end_node1->next = head3;
  end_node2->next = head3;
  pre_node = head3;
  for (int i = 20; i < 22; i++) {
    ListNode *node = new ListNode(i);
    pre_node->next = node;
    pre_node = node;
  }

  LiskListSolution sol;
  // sol.printall(head);

  cout << std::endl;

  cout << sol.hasCycle(head);
  cout << sol.getIntersectionNode(head, head2);
  sol.sortList(head);
  /*ListNode *newHead = sol.reverseBetween(head,1,2);
*/
  sol.printall(head);

  ListNode *pn = head;
  ListNode *next = head;
  while (pn != NULL) {
    next = pn->next;
    delete pn;
    pn = next;
  }
  return 0;
}
