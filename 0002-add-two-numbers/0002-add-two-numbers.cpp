class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while (l1) {
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
            temp = temp->next;
        }

        temp = ans;
        int val=0, over=0;
        while (l2) {
            if (temp->next) {
                val = temp->next->val + l2->val + over;
                temp->next->val = val % 10;
                over = val / 10;
            } else {
                val = l2->val + over;
                over = val / 10;
                temp->next = new ListNode(val %10);
            }
            temp = temp->next;
            l2 = l2->next;
        }

        while(over != 0){
            if(temp->next){
                val = temp->next->val + over;
                over = val / 10;
                temp->next->val = val % 10;
            }else{
                temp->next = new ListNode(1);
                over =0;
            }
            temp = temp->next;
        }

        return ans->next;
    }
};