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
        if(!head) return head;
        Node* curr1=head;
        while(curr1){
            Node* copy=new Node(curr1->val);
            copy->next=curr1->next;
            curr1->next=copy;
            curr1=copy->next;
        }

        curr1=head;
        Node* head2=curr1->next;
        Node* curr2=head2;
        while(curr1){
            curr2=curr1->next;
            if(curr1->random) curr2->random=curr1->random->next;
            curr1=curr1->next->next;
        }
        curr1=head;
        while(curr1){
            curr2=curr1->next;
            Node* temp=curr2->next;
            if(temp){
                curr2->next=temp->next;
            }
            curr1->next=temp;
            curr1=temp;
        }
        return head2;
    }
};
