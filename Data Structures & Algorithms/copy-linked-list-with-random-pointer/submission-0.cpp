/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* copyRandomList(Node* head) {
        if( head == nullptr){
            return nullptr;
        }
        Node* newNode;
        if(m[head]){
            newNode = m[head];
        }else{
            newNode = new Node(head->val);
            m[head] = newNode;
        }                
        if(head->random){
            if(m[head->random]){
                newNode->random = m[head->random];
            }else{
                newNode->random = new Node(head->random->val);
                m[head->random] = newNode->random;
            }            
        }
        else{            
            newNode->random = nullptr;
        }
        newNode->next = copyRandomList(head->next);        
        return newNode;
    }
};
