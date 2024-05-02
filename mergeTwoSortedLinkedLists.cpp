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
  public: ListNode *mergeTwoLists(ListNode * list1, ListNode * list2) {
    ListNode *head = new ListNode; // Create a new linked list
    ListNode *current; // Create a variable to track the current node in the new linked list

    if (list1 == nullptr) return list2; // If the list is empty, return the other list.
    if (list2 == nullptr) return list1; // If the list is empty, return the other list.

    if (list1->val <= list2->val) { // Compare both values and assign the smaller as the first node (head) in the new linked list
      head = list1;
      list1 = list1->next;
    } else {
      head = list2;
      list2 = list2->next;
    }

    current = head; // Assign current to be the head (start of the new linked list)

    while (list1 != NULL && list2 != NULL) { // Continuously compare both values so long as both lists are not NULL
      if (list1->val <= list2->val) {
        current->next = list1; // Update the new linked list's next node to the smaller value
        list1 = list1 ->next; // Move to the next node in the list which had the smaller value
      } else {
        current->next = list2; // Update the new linked list's next node to the smaller value
        list2 = list2->next; // Move to the next node in the list which had the smaller value
      }

      current = current->next; // Move to the next node in the new linked list

    }

    if (list1 != nullptr) { // If either of the lists are still not empty, append the remainder of the list to the merged linked list.
      current->next = list1;
    } else {
      current->next = list2;
    }

    return head; // Return the head of the merged linked  list.
  }
};
