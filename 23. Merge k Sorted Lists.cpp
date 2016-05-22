
  // Definition for singly-linked list.
 // struct ListNode {
 //      int val;
 //      ListNode *next;
 //      ListNode(int x) : val(x), next(NULL) {}
 // };
 
class Solution {

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

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (lists.size() == 0) return NULL;
    	vector<ListNode*> new_lists;
    	int i = 0, j = lists.size()-1;
    	while (i < j) {
    		ListNode * l = mergeTwoLists(lists[i++], lists[j--]);
    		new_lists.push_back(l);
    	}
    	if (i == j) {
    		new_lists.push_back(lists[i]);
    	}
    	if (new_lists.size() == 1) {
    		return new_lists[0];
    	} else {
    		return mergeKLists(new_lists);
    	}
    }
};



