/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hashMap; // Create a hashmap
        Node* cur = head; // Create a pointer to the head of the linked list
        while(cur){ // While the pointer is not null
            Node* copy = new Node(cur->val); // Create a copy of the node 
            hashMap[cur] = copy; // Append it to the hashmap
            cur = cur->next; // Move onto the next node
        }

        Node* curr = head; // Create a new pointer to the head of the linked list
        while(curr){ // While the pointer is not null
            Node* copy1 = hashMap[curr]; // Create a copy of the node in the hashmap
            copy1->next = hashMap[curr->next]; // Link the copied node with it's next node obtained from the hashmap
            copy1->random = hashMap[curr->random]; // Link the copied node with it's random node obtained from the hashmap
            curr = curr->next; // Move onto the next node
        }
        return hashMap[head];
    }
};
