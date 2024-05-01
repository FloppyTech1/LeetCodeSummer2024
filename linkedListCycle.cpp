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
    bool hasCycle(ListNode* head) {
        if (head == NULL){ // If head is NULL return false
            return false;
        }
        ListNode* slow = head; // Create a slow pointer which moves 1 node at a time
        ListNode* fast = head; // Create a fast pointer which moves 2 nodes at a time
        while (fast && fast->next) { // While fast is not null
            slow = slow->next; // Move slow up one node
            fast = fast->next->next; // Move fast up two nodes
            if (slow == fast) { // If they are equivalent, return true
                return true;
            }
        }
        return false; // Else return false
    }
};
