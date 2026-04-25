/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for(auto elem: cur->neighbors){
                if(!oldToNew.contains(elem)){
                    oldToNew[elem] = new Node(elem->val);
                    q.push(elem);
                }
                oldToNew[cur]->neighbors.emplace_back(oldToNew[elem]);
            }
        }
        return oldToNew[node];
    }
};
