class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        while(list1){
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;

        }

        while(list2){
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
        return ans->next;
    }
};