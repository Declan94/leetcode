/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode *p1 = l1, *p2 = l2;
    	ListNode *tail = NULL, *head = NULL;
    	while (p1 || p2) {
    		ListNode * p = NULL;
    		bool add_p1;
    		if (!p1) {
    			add_p1 = false;
    		} else if (!p2) {
    			add_p1 = true;
    		} else {
    			add_p1 = (p1->val < p2->val);
    		}
    		if (add_p1) {
    			p = p1;
    			p1 = p1->next;
    		} else {
    			p = p2;
    			p2 = p2->next;
    		}
    		if (tail) {
    			tail->next = p;
    		} else {
    			head = p;
    		}
    		tail = p;
    	}   
    	return head;
    }
};