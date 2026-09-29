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
        ListNode* slow= head,* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* cur = slow->next;
        slow->next= nullptr;
        ListNode* pre = nullptr; 
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;

        }
        slow->next= nullptr;
        ListNode *temp1 = head, *temp2 = pre;
        while(head && pre){
            temp1 = head->next;            
            temp2 = pre->next;
            head->next = pre;
            pre->next = temp1;
            head = temp1;
            pre = temp2;
        }
        if(pre)pre->next = nullptr;
    }
};
