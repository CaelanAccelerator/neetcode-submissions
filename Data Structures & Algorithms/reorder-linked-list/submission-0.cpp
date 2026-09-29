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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        queue<ListNode*> q;
        ListNode* cur = head;
        while(cur){
            s.push(cur);
            cur = cur->next;
            
        }
        ListNode* cur2 = head;
        ListNode* curN = head;
        bool done = true;
        while(!s.empty() && cur2 && done){
            if(cur2 == s.top() || cur2->next == s.top()) done = false;
            curN = cur2->next;
            cur2->next = s.top();
            s.top()->next = nullptr;
            cout<<cur2->val<<endl;
            q.push(cur2);
            s.pop();
            cur2 = curN;
        }
        while(!q.empty()){
            ListNode* cur = q.front();
            // cout<<cur->val<<endl;
            q.pop();
            if(!q.empty()&& cur && cur->next)
                cur->next->next = q.front();
        }
        
    }
};
