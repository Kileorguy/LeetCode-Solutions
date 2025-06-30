class Solution {
public:

    ListNode *swap(ListNode *slow, ListNode *fast, ListNode *p){

        ListNode *prev = nullptr, *curr = slow, *next = nullptr;
        while(curr && curr !=fast){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode(-1, head);
        ListNode *slow = head, *fast = head;
        ListNode *p = ans;
        int count = 0;
        do{
            count = 0; 
            for(int i=0;i<k && fast;i++){
                fast = fast->next;
                count++;
            }
            if(count < k) break;
            ListNode *temp = swap(slow,fast, p);
            p->next = temp;
            p = slow;
            slow->next = fast;
            slow = fast;

        }while(count >= k);

        return ans->next;

    }
};