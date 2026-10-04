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
        ListNode* cur1 = l1, *cur2 = l2;
        ListNode* pre = cur1;
        int carrier = 0;
        while(cur1){
            cur1->val += carrier;
            carrier = 0;
            if(cur2 != nullptr){
                cur1->val += cur2->val;
            }
            if(cur1->val > 9){
                carrier = (cur1->val) / 10;
                cur1->val -= 10;
            }
            if(cur1->next == nullptr && cur2 != nullptr){
                cur1->next = cur2->next;
                cur2 = nullptr;
            }
            pre = cur1;
            cur1 = cur1->next;
            if(cur2 != nullptr){               
                cur2 = cur2->next;   
            }      
        }
        if(carrier > 0){
            pre->next = new ListNode(carrier);
        }
        return l1;
    }
};
