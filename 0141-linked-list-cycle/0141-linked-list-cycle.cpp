class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast){
            for(int i=0; i<2 && fast; i++){
                fast = fast->next;
                if(fast == slow) return true;
            }
            slow = slow->next;
        }
        return false;
        
    }
};