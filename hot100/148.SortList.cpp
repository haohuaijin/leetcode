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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        int size = 0;
        ListNode* node = head;
        while(node != nullptr){
            node = node->next;
            size += 1;
        }

        ListNode* dummy = new ListNode(0, head);
        for(int len = 1; len < size; len = len*2){
            ListNode* prev = dummy;
            ListNode* cur = dummy->next;
            while(cur != nullptr){
                ListNode* h1 = cur;
                for(int i = 1; i < len && cur->next != nullptr; i++){
                    cur = cur->next;
                }

                ListNode* h2 = cur->next;
                cur->next = nullptr;
                cur = h2;
                for(int i = 1; i < len && cur != nullptr && cur->next != nullptr; i++){
                    cur = cur->next;
                }

                ListNode* next = nullptr;
                if(cur != nullptr){
                    next = cur->next;
                    cur->next = nullptr;
                }
                
                ListNode* res = merge(h1, h2);
                prev->next = res;
                while(prev->next != nullptr){
                    prev = prev->next;
                }
                cur = next;
            }
        }
        return dummy->next;
    }
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* t1 = h1;
        ListNode* t2 = h2;
        while(t1 != nullptr && t2 != nullptr){
            if(t1->val >= t2->val){
                cur->next = t2;
                t2 = t2->next;
            } else {
                cur->next = t1;
                t1 = t1->next;
            }
            cur = cur->next;
        } 
        if(t1 != nullptr){
            cur->next = t1;
        } else if(t2 != nullptr){
            cur->next = t2;
        }
        return dummy->next;
    }
};
