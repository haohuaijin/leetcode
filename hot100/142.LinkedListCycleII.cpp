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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        } 
        ListNode* slow = head;
        ListNode* fast = head;

        do {
            if(fast == nullptr || fast->next == nullptr){
                return nullptr;
            } 
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast);

        ListNode* cur = head;
        while(cur != slow){
            cur = cur->next;
            slow = slow->next;
        }
        return cur;
    }
};
