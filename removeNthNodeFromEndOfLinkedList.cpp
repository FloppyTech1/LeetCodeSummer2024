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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyNode = new ListNode(); // Create a dummy node
        dummyNode->next = head; // Assign the dummy node to the head of the linked list
        ListNode *slow, *fast; // Create a slow and fast pointer
        slow = dummyNode; // Assign the slow pointer to start before the head
        fast = head; // Assign the fast pointer to start at the head

        // Move the faster pointer n times to create a gap between fast and slow
        for(int i = 0; i < n; i++) {
            if (fast == nullptr) 
                return head;
            fast = fast->next;
        }

        // Move both pointers by one till fast reaches the end of the list, which also means we have reached the Nth node
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the nth node by moving it's link to the final node
        slow->next = slow->next->next;
        // Return the head
        return dummyNode->next;
    }
};
