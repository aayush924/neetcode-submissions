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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, decltype([](const ListNode* a, const ListNode* b){
            return a->val>b->val;
        })> pq;
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        for(auto& node: lists){
            if(node) pq.push(node);
        }
        while(!pq.empty()){
            temp->next=pq.top();
            temp=temp->next;
            pq.pop();
            if(temp->next) pq.push(temp->next);
        }
        return dummy->next;
    }
};
