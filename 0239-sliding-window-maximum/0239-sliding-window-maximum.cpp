class Solution {
public:

    vector<int> arr;

    void pushPriorityQueue(int val){
        if(arr.empty()) arr.push_back(val);
        else if(arr[0] < val ){
            // push head 
            arr.insert(arr.begin(), val);
        }else if(arr.back() >= val){
            arr.insert(arr.end(), val);
        }else{
            auto it = lower_bound(arr.begin(), arr.end(), val, [](int a, int b){return a > b;});
            arr.insert(it, val);
        }
    }

    

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int len = nums.size();

        for(int i=0;i<k;i++){
            pushPriorityQueue(nums[i]);
        }
        ans.push_back(arr[0]);
        
        for(int i=1; i<len-k+1; i++){
            auto it = lower_bound(arr.begin(), arr.end(),nums[i-1],
                [](int a,int b){return a>b;});
            arr.erase(it);


            pushPriorityQueue(nums[i+k-1]);
            ans.push_back(arr[0]);
        }
       
        return ans;
    }
};