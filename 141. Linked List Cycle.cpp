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
    bool hasCycle(ListNode *head) {
        ListNode * flag = new ListNode(0);
        while (head) {
        	if (head == flag) return true;
        	ListNode * p = head;
        	head = head->next;
        	p->next = flag;
        }
        return false;
    }
};