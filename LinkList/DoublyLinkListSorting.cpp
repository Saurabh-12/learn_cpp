class Solution {
public:
    // Function to merge two sorted doubly linked lists.
    Node* merge(Node* left, Node* right) {
        // If any of the lists is empty, return the other one.
        if (!left) return right;
        if (!right) return left;
        
        // Choose the smaller value node among left and right
        // and recursively merge the remaining lists.
        if (left->data < right->data) {
            left->next = merge(left->next, right);
            left->next->prev = left;
            left->prev = NULL;
            return left;
        } else {
            right->next = merge(left, right->next);
            right->next->prev = right;
            right->prev = NULL;
            return right;
        }
    }
    
    // Function to get the middle of the doubly linked list.
    Node* getMiddle(Node* head) {
        if (!head || !head->next) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Function to perform merge sort on a doubly linked list.
    Node* sortDoubly(Node* head) {
        if (!head || !head->next) return head;
        
        // Get the middle node of the list.
        Node* mid = getMiddle(head);
        Node* nextToMid = mid->next;
        
        // Divide the list into two halves.
        mid->next = NULL;
        nextToMid->prev = NULL;
        
        // Recursively sort the two halves.
        Node* left = sortDoubly(head);
        Node* right = sortDoubly(nextToMid);
        
        // Merge the sorted halves.
        return merge(left, right);
    }
};