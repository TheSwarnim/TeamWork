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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr){
            slow = slow->next;
        }
        
        slow = reverse(slow);
        
        while(slow != NULL){
            if(slow->val != head->val) return false;
            slow =slow->next;
            head =head->next;
        }
        
        return true;
    }
    
    ListNode *reverse(ListNode *node){
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        while(node != nullptr){
            next = node->next;
            node->next = prev;
            
            prev = node;
            node = next;
        }
        
        return prev;
    }
};