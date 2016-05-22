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
    ListNode* oddEvenList(ListNode* head) {
        bool odd = true;
        ListNode * ot = NULL, * et = NULL, *eh = NULL;
        ListNode * p = head;
        while (p) {
        	if (odd) {
        		if (ot) {
        			ot->next = p;
        		}
        		ot = p;
        	} else {
        		if (et) {
        			et->next = p;
        		} else {
        			eh = p;
        		}
        		et = p;
        	}
        	odd = !odd;
        	p = p->next;
        }
        if (ot) {
        	ot->next = eh;
        }
        if (et) {
        	et->next = NULL;
        }
        return head;
    }
};