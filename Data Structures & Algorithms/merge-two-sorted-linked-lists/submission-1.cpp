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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* result = new ListNode();
        ListNode* resCur = new ListNode();

        result = resCur;
        while(list1 && list2){
            if(list1->val > list2->val){
                resCur->next = list2;
                list2 = list2->next;
            }else{
                resCur->next = list1;
                list1 = list1->next;
            }
            resCur = resCur->next;
        }

        if(list1){
            resCur->next = list1;
        }else{
            resCur->next = list2;
        }
        result = result->next;
        return result;
    }
};
