class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        bool allNegative = true;
        for(int &x: nums){
            if(x > 0) allNegative = false;
            s.insert(x);
        }
        // cout << allNegative << endl;

        if(allNegative){
            int last = *s.rbegin();
            return last;
        }
        int sum = 0;
        for(int a: s){
            if(a > 0){
                sum+=a;
            }
        }

        return sum;
    }
};