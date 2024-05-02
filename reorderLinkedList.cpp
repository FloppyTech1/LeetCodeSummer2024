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
    void reorderList(ListNode* head) {
        if (!head || !head->next) // Check if the linked list is empty or does not contain at least 3 nodes
            return;
        
        ListNode *node1, *node2, *current;  // Create two nodes to be the heads of the first half and second half of the linked list as well as a current pointer to help build the reordered list
        ListNode* slow = head; // Create a slow pointer which moves 1 node at a time
        ListNode* fast = head; // Create a fast pointer which moves 2 nodes at a time
        while (fast && fast->next) { // While fast is not null
            slow = slow->next; // Move slow up one node
            fast = fast->next->next; // Move fast up two nodes
        }
        node1 = head; // Set the first node to the first half of the list
        node2 = slow->next; // Set the second node to the second half of the list
        slow->next = nullptr; // Terminate the first part of the list
        
        node2 = reverseList(node2); // Reverse the second half of the list
        
        ListNode *dummyHead = new ListNode(); // Dummy head for the reordered list
        current = dummyHead; // Set the current pointer to the head to traverse the list
        
        while(node1 != nullptr || node2 != nullptr){ // While both, or at least one of the lists are not empty
            if(node1 != nullptr){
                current->next = node1; // Append the element from the first half of the list first
                current = current->next; // Move to the next node in the reordered list
                node1 = node1->next; // Move to the next node in the first half of the list
            }
            if(node2 != nullptr){
                current->next = node2; // Append the element from the second half of the list second
                current = current->next; // Move to the next node in the reordered list
                node2 = node2->next; // Move to the next node in the second half of the list
            }
        }
        
        head = dummyHead->next; // Update the head of the reordered list
        delete dummyHead; // Free the memory of the dummy head
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *current, *prev, *next; // Define 3 variables, current, prev and next to keep track of the current node, the previous node, and the next node
        current = head; // Set the current node initally to head so we start at the head
        prev = nullptr; // Set the previous node initially to NULL as the first link reverse we make will point to NULL
        while(current != nullptr){ // While the current node is not NULL
            next = current->next; // Store the next node's address in the next variable
            current->next = prev; // Change the current node's address to the previous
            prev = current; // Update the previous node to now be the current node
            current = next; // Update the current node to now be the next node
        }
        return prev; // Return the new head of the reversed list
    }
};
