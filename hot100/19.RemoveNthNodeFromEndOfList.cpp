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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        while(n > 0){
            second = second->next;
            n--;
        } 
        while(second->next != nullptr){
            second = second->next;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};
