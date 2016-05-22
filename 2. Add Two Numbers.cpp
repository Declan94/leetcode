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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = NULL, *tail = NULL, *p1 = l1, *p2 = l2;
        while (p1 || p2 || carry > 0) {
        	int v1 = p1 ? p1->val : 0;
        	int v2 = p2 ? p2->val : 0;
        	int v = v1 + v2 + carry;
        	carry = v / 10;
        	auto p = new ListNode(v % 10);
        	if (tail) {
        		tail->next = p;
        	} else {
        		head = p;
        	}
        	tail = p;
        	p1 = p1 ? p1->next : NULL;
        	p2 = p2 ? p2->next : NULL;
        }
        tail->next = NULL;
        return head;
    }
};