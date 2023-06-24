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
        ListNode* fast = head;
        ListNode* slow = head; 
        while(fast != nullptr){
            fast = fast->next;
            if(fast != nullptr)
                fast = fast->next;
            slow = slow->next;
        }

        // can record it in prev loop
        ListNode* prevSlow = head;
        while(prevSlow != nullptr){
            if(prevSlow->next == slow){
                break;
            }
            prevSlow = prevSlow->next;
        }

        ListNode* mid = reverseList(slow);

        // verified palindrome
        ListNode* left = head;
        ListNode* right = mid;
        while(right != nullptr){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }

        // restore list
        if(prevSlow != nullptr){
            prevSlow->next = reverseList(mid);
        }
        return true;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* ptr = head;
        while(head != nullptr){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};
