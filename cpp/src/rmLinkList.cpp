#include "iostream"
using namespace std;
/**
* Definition for singly-linked list.
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pAnode = headA;
		ListNode *pBnode = headB;

		while (pAnode)
		{
			while (pBnode)
			{

			}

		}
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
		return nullptr;
	}
	bool hasCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}

	ListNode* reverseBetween2(ListNode* head, int m, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *prev = &dummy;
		for (int i = 0; i < m - 1; ++i)
			prev = prev->next;
		ListNode* const head2 = prev;
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head)
			return head;

		if (m == n)
		{
			return head;
		}
		ListNode *next_node;
		ListNode *cur_node=head;
		ListNode *prev_node=head;
		prev_node = head;
		ListNode *start_node=head->next;
		ListNode *end_node=head;
		int node_idx = 1;
		while (cur_node)
		{
			if (node_idx < m)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
			}
			else if (node_idx == m)
			{
				end_node = prev_node;
				start_node = cur_node;
				cur_node = cur_node->next;
			}
			else if (node_idx < n)
			{
				next_node = cur_node->next;
				cur_node->next = prev_node;
				prev_node = cur_node;
				cur_node = next_node;
			}
			else if ( node_idx == n)
			{
				start_node->next = next_node = cur_node->next;
				cur_node->next = prev_node;
				end_node->next = cur_node;
				if (m==1)
				{
					head->next = NULL;
					head = cur_node;
				}
				cur_node = next_node;
			}
			node_idx++;

		}

		return head;

	}
	int traversal(ListNode *head)
	{
		ListNode *pn = head;
		int node_num = 0;
		while (pn != NULL)
		{
			node_num ++ ;
			pn = pn->next;
		}
		return node_num;
	}
	void printall(ListNode *head)
	{
		ListNode *pn = head;
		while (pn != NULL)
		{
			std::cout << pn->val << '\t';
			pn = pn->next;
		}
	}
};
int main(char argc, char** argv)
{
	ListNode *head = new ListNode(-1);
	ListNode *pre_node = head;

	for (int i = 0; i < 1; i++)
	{
		ListNode* node = new ListNode(i);
		pre_node->next = node;
		pre_node = node;

	}
	pre_node->next = head;

	Solution sol;
	//sol.printall(head);

	cout << std::endl;

	cout << sol.hasCycle(head);
	/*ListNode *newHead = sol.reverseBetween(head,1,2);

	sol.printall(newHead);
*/
	ListNode *pn = head;
	ListNode *next = head;
	while (pn != NULL)
	{
		next = pn->next;
		delete pn;
		pn = next;
	}
	return 0;
}
