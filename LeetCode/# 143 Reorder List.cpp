// 2013-11-02 

/* Question:
 *	Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
 *	reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
 *
 *	You must do this in-place without altering the nodes' values.
 *  
 *	For example,
 *	Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>

using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};

#ifdef _HAHA_THIS_IS_A_CHEAT_WAY_
class Solution {
public:
	void reorderList(ListNode *head) 
	{
		ListNode * pCurrentNode = head;
		vector<int> ListAddr;

		if(head == nullptr)
			return;

		while(pCurrentNode)
		{
			ListAddr.push_back((int)pCurrentNode);
			pCurrentNode = pCurrentNode->next;
		}
		int n = ListAddr.size();
		head->next = (ListNode *)ListAddr[n-1];
		pCurrentNode = head->next;
		pCurrentNode->next = nullptr;
		for(int i = 1, j = n-2; i <= j; i++, j--)
		{
			pCurrentNode->next = (ListNode *)ListAddr[i];
			pCurrentNode = pCurrentNode->next;
			pCurrentNode->next = (ListNode *)ListAddr[j];
			pCurrentNode = pCurrentNode->next;
		}
		pCurrentNode->next = nullptr;
	}
};
#else
class Solution {
public:
	void reorderList(ListNode *head) 
	{
		ListNode * pTailList = head, * pCurrentNode = head;

		if(head == nullptr)
			return;

		while(pCurrentNode)		/* this is to find the middle node of this List. */
		{
			pCurrentNode = pCurrentNode->next;
			if(pCurrentNode)
			{
				pCurrentNode = pCurrentNode->next;
				pTailList = pTailList->next;
			}
		}
		ListNode list(0);
		list.next = pTailList->next;
		pTailList->next = nullptr;

		pCurrentNode = list.next;
		list.next = nullptr;
		while(pCurrentNode)
		{
			pTailList = list.next;
			list.next = pCurrentNode;
			pCurrentNode = pCurrentNode->next;
			list.next->next = pTailList;			
		}

		pCurrentNode = head->next;
		ListNode * headNodeLit = head;
		pTailList = list.next;
		while(pCurrentNode && pTailList)
		{
			headNodeLit->next = pTailList;
			headNodeLit = headNodeLit->next;
			pTailList= pTailList->next;

			headNodeLit->next = pCurrentNode;
			headNodeLit = headNodeLit->next;
			pCurrentNode = pCurrentNode->next;	
		}
		if(pCurrentNode)
		{
			headNodeLit->next = pCurrentNode;
			headNodeLit = headNodeLit->next;
		}
		headNodeLit->next = nullptr;
	}
};
#endif

int main()
{
	ListNode list(1);

	/*ListNode node1(2);
	ListNode node2(3);
	ListNode node3(4);
	ListNode node4(5);
	ListNode node5(6);
	ListNode node6(7);

	list.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;*/

	Solution s;

	s.reorderList(&list);
}