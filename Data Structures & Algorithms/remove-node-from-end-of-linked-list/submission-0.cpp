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
        ListNode*end =  head;
        while(n-- > 0){
            end = end->next;
        }
        ListNode*cur = head;
        if(end == nullptr){
            return head->next;
        }
        while(end->next){
            cur = cur->next;
            end = end->next;
        }        
        cur->next = cur->next->next;
        return head;
    }
};
