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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p = head;
        ListNode * t = head->next;
        for (int i=0; i<n; i++) {
        	if (!t) {
        		p = head->next;
        		delete(head);
        		return p;
        	}
        	t = t->next;
        }
        while (t) {
        	p = p->next;
        	t = t->next;
        }
        ListNode * q = p->next;
        p->next = q->next;
        delete(q);	
        return head;
    }
};