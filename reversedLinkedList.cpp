/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current, *prev, *next; // Define 3 variables, current, prev and next to keep track of the current node, the previous node, and the next node
        current = head; // Set the current node initally to head so we start at the head
        prev = NULL; // Set the previous node initially to NULL as the first link reverse we make will point to NULL
        while(current != NULL){ // While the current node is not NULL
            next = current->next; // Store the next node's address in the next variable
            current->next = prev; // Change the current node's address to the previous
            prev = current; // Update the previous node to now be the current node
            current = next; // Update the current node to now be the next node
        }
        head = prev; // Update the head to now be the last node we traversed
        return head; // Return the head
    }
};
