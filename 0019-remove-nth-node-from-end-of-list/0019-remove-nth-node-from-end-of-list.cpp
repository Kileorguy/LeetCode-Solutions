class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *second = head, *first = head, *prev=head;
        for(int i=0;i<n;i++){
            second = second->next;
        }

        while(second){
            second = second->next;
            prev = first;
            first = first->next;
        }

        if(prev == first){
            if(first && first->next){
                head = head->next;
            }else{
                head = nullptr;

            }
        }else{
            prev->next = first->next;
        }
        return head;
    }
};