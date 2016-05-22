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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * a = NULL;
        auto b = head;
        auto c = head->next;
        auto new_head = c;
        while (b && c) {
        	if (a) a->next = c;
        	b->next = c->next;
        	c->next = b;
        	a = b;
        	b = b->next;
        	if (b) c = b->next;
        }
        return new_head;
    }
};