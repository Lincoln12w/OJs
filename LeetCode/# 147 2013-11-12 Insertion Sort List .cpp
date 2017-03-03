/*	Question:
 *	Sort a linked list using insertion sort. 
 */

/**
 *	Definition for singly-linked list. 
 *	struct ListNode {
 *		int val;
 *		ListNode *next;
 *		ListNode(int x) : val(x), next(nullptr) {}
 *	};
 */
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) 
	{
		ListNode list(0);
		list.next = head;
		ListNode * cur = head;
		while(cur != nullptr)
		{
			ListNode * temp = cur;
			cur = cur->next;
			temp->next = nullptr;
			for(ListNode * ptr = &list; ptr != temp; ptr = ptr->next)
			{
				if(ptr->next == nullptr)
				{
					ptr->next = temp;
					break;
				}
				if(ptr->next->val > temp->val)
				{
					temp->next = ptr->next;
					ptr->next = temp;
					break;
				}
			}
		}
		return list.next;
	}
};

/* test func */
int main()
{
	ListNode node1(1);
	ListNode node2(1);
	node1.next = &node2;
	Solution s;
	s.insertionSortList(&node1);

	return 0;
}