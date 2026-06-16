#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // Move both until fast reaches the end
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Delete the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};