class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Map original node -> cloned node
        unordered_map<Node*, Node*> clones;
        queue<Node*> q;

        // Create the clone for the starting node
        clones[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                // If neighbor hasn't been cloned yet, create it and enqueue
                if (!clones.count(neighbor)) {
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Connect the cloned neighbor to the cloned curr node
                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};