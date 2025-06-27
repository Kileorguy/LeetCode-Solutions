class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode();
        ListNode *ans = head;
        int len = lists.size();

        while(true){
            bool empty = true;

            for(ListNode* x : lists){
                if(x) empty = false;
            }
            if(empty) break;

            int lowestIdx = 0, lowestVal = INT_MAX;
            for(int i=0; i<len; i++){
                if(lists[i] && lowestVal > lists[i]->val){
                    lowestVal = lists[i]->val;
                    lowestIdx = i;
                }
            }

            ans->next = lists[lowestIdx];
            lists[lowestIdx] = lists[lowestIdx]->next;
            ans = ans->next;
            ans->next = nullptr;

        }

        return head->next;
    }
};