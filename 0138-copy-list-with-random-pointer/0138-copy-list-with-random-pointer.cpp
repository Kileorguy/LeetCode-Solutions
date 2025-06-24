class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ans = new Node(0);
        Node *ansTemp = ans;
        unordered_map<Node*, Node*> um;
        Node *temp = head;
        while(temp){
            Node *newNode = new Node(temp->val);
            um[temp] = newNode;
            temp = temp->next;
        }



        while(head){
            Node *next = head->next, *random = head->random;

            ansTemp->next = um[head];
            ansTemp->next->random = um[random]; 

            ansTemp = ansTemp->next;
            head = head->next;
        }

        return ans->next;
    }
};