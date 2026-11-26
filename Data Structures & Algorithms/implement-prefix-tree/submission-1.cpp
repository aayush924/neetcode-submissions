class Node {
public:
    Node* links[26]={}; // Zero-initializes all 26 pointers to nullptr
    bool flag = false;
};

class PrefixTree {
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->links[c - 'a']) {
                curr->links[c - 'a'] = new Node();
            }
            curr = curr->links[c - 'a'];
        }
        curr->flag = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->links[c - 'a']) return false;
            curr = curr->links[c - 'a'];
        }
        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (!curr->links[c - 'a']) return false;
            curr = curr->links[c - 'a'];
        }
        return true;
    }
};