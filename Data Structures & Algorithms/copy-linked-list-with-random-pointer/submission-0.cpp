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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyMap;
        Node* curr1=head;
        Node* curr2= new Node(0);
        while(curr1){
            Node* newNode= new Node(curr1->val);
            curr2->next=newNode;
            curr2=curr2->next;
            copyMap[curr1]=curr2;
            curr1=curr1->next;
        }
        curr1=head;
        curr2=copyMap[curr1];

        while(curr1){
            if(curr1->random) curr2->random=copyMap[curr1->random];
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return copyMap[head];
    }
};
