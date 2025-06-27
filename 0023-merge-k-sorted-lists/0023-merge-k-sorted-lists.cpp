class Solution {
public:

    ListNode *merge(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    ListNode *divide(vector<ListNode*>& lists, int left, int right){
        if(left == right) return lists[left];
        int mid = left + (right-left)/2;
        
        ListNode *l1 = divide(lists, left, mid);
        ListNode *l2 = divide(lists, mid+1, right);

        return merge(l1, l2);
        

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int len = lists.size();
        return divide(lists, 0 ,len-1);
    }
};