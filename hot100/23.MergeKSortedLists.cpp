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
    bool cmp(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
		//这里可以使用结构体对ListNode包装一层，实现起来更加优雅
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(std::bind(&Solution::cmp, this, std::placeholders::_1, std::placeholders::_2))> heap(std::bind(&Solution::cmp, this, std::placeholders::_1, std::placeholders::_2));
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
                heap.push(lists[i]);
            }
        }
        while(!heap.empty()){
            ListNode* curr = heap.top();
            heap.pop();
            head->next = curr;
            head = head->next;  
            if(curr->next != nullptr){
                heap.push(curr->next);
            }
        }
        return dummy->next;
    }
};

