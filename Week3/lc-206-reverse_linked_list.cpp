#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next_node = curr->next; // Save the rest of the list
            curr->next = prev;                // Reverse the link
            prev = curr;                      // Move prev forward
            curr = next_node;                 // Move curr forward
        }
        
        return prev;                          // prev is the new head
    }
};