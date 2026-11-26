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
    Node* dfs(Node* node, unordered_map<Node*, Node*>& clones){
        if(clones.count(node)) return clones[node];
        Node* clone =new Node(node->val);
        clones[node]=clone;
        for(auto& neighbor: node->neighbors){
            clone->neighbors.push_back(dfs(neighbor, clones));
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> clones; //original->clones
        return dfs(node, clones);
    }
};
