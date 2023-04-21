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
        ListNode* res = new ListNode();
        ListNode* head = res;
        int rem = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL) {
                rem += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                rem += l2->val;
                l2 = l2->next;
            }
            head->next = new ListNode(rem % 10);
            head = head->next;
            rem = rem / 10;
        }
        if(rem != 0){
            head->next = new ListNode(rem);
        }
        return res->next;
    }
};
