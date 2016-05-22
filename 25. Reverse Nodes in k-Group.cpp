/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	ListNode * new_head;
	ListNode * reverse(ListNode* before, ListNode* head, int k) {
		auto tail = head;
		for (int i = 0; i < k-1; ++i)
		{
			tail = tail->next;
			if (!tail) return NULL;
		}
		if (before) 
			before->next = tail;
		else
			this->new_head = tail;
		ListNode * after = tail->next;
		auto p = head;
		while (after != tail) {
			auto q = p->next;
			p->next = after;
			after = p;
			p = q;
		}
		return tail;
	}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if (k == 1 || !head) return head;
    	this->new_head = head;
        ListNode * before = NULL;
        ListNode * tail = NULL;
        auto p = head;
        do {
        	tail = reverse(before, p, k);
        	before = p;
        	p = p->next;
        } while (tail && p);
        return this->new_head;
    }
};