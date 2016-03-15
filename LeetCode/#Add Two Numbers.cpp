/*  Question:
 *  You are given two linked lists representing two non-negative numbers. 
 *  The digits are stored in reverse order and each of their nodes contain a single digit. 
 *  Add the two numbers and return it as a linked list.
 * 
 *  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 0 -> 8
 */

/**
 *	Definition for singly-linked list.
 *	struct ListNode 
 *	{
 *		int val;
 *		ListNode *next;
 *		ListNode(int x) : val(x), next(nullptr) {}
 *	};
 */

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
	public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		//ListNode list(((l1->val)+(l2->val))%10);	/*never return a pointer to a local value.*/
		ListNode list(0)
		ListNode * cur = &list;
		int sum = 0;

		while(l1 || l2 || sum)
		{
			if(l1)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if(l2)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			sum = sum / 10;
		}

		return list.next;
	}
};

/* test func */
int main()
{
	ListNode l1(1);
	ListNode l11(8);
	//ListNode l12(3);
	l1.next = &l11;
	//l11.next = &l12;

	ListNode l2(0);
	//ListNode l21(2);
	//ListNode l22(4);
	//l2.next = &l21;
	//l21.next = &l22;

	Solution s;
	ListNode * l3 = s.addTwoNumbers(&l1, &l2);

	return 0;
}