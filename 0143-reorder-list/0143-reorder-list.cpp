class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode *temp = head;
        ListNode *prev = nullptr, *curr;
        int count = 0;
        while(temp){
            curr = new ListNode(temp->val, prev);
            prev = curr;
            temp = temp->next;
            count++;
        }

        ListNode *main = head;
        ListNode *rev = curr;

        ListNode *TM = head, *TR = curr;

        ListNode *trav = head;

        int ctr = 1;

        while(trav && TM && TR){
            // cout << count << " " + to_string(ctr) << endl;
            TM = TM->next;
            trav->next = TR;
            trav = trav->next;
            ctr++;
            if(ctr == count) break;
            
            TR = TR->next;
            trav->next = TM;
            trav = trav->next;
            ctr++;
            if(ctr == count) break;
        }
        if(trav){
            trav->next = nullptr;
        }else{
            head->next = nullptr;
        }
    }
};