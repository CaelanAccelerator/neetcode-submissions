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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* cur = head;
        while(cur->next){
            cur = cur->next;
        }
        reverseRec(head);
        head->next = nullptr;
        return cur;
    }

    ListNode* reverseRec(ListNode* head) {
        if(head->next == nullptr) 
            return head;
        reverseRec(head->next)->next = head;
        return head;
    }
};
