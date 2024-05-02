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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyNode = new ListNode(); // Create a dummy node
        ListNode *cur; // Create a pointer 
        cur = dummyNode; // Assign pointer to the dummy node
        int val1, val2, val, carry = 0; // Variables

        while(l1 || l2 || carry){ // While either list or carry is not null
            if(l1){ // If list is not null, grab the value of the current node
                val1 = l1->val;
            }
            else{ // Else 0
                val1 = 0;
            }

            if(l2){ // If list is not null, grab the value of the current node
                val2 = l2->val;
            }
            else{ // Else 0
                val2 = 0;
            }

            val = val1 + val2 + carry; // Add the values and carry
            carry = val / 10; // Check for another carry
            val = val % 10; // Only need 1's place value

            cur->next = new ListNode(val); // Create a new node with the result of val
            cur = cur->next; // Move to the next node
            if(l1){ // If list is not empty, move to the next node, else stay null
                l1 = l1->next;
            }
            else{
                l1 = nullptr;
            }

            if(l2){ // If list is not empty, move to the next node, else stay null
                l2 = l2->next;
            }
            else{
                l2 = nullptr;
            }

            }
            return dummyNode->next; // Return head of dummmy node
        }
};
