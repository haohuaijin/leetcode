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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        ListNode* tempA = headA;
        while(tempA != nullptr){
            lenA += 1;
            tempA = tempA->next;
        }
        int lenB = 0;
        ListNode* tempB = headB;
        while(tempB != nullptr){
            lenB += 1;
            tempB = tempB->next;
        }

        if(lenA > lenB){
            int count = lenA - lenB;
            while(count--){
                headA = headA->next;
            }
        } else {
            int count = lenB - lenA;
            while(count--){
                headB = headB->next;
            }
        }
        while(headA != nullptr && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
