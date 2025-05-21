class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int peak = 0;

        for(int s:us){
            if(us.find(s-1) == us.end()){
                // kalo gaada -1nya
                int length = 1;
                while(us.find(s+length) != us.end()){
                    length+=1;
                }
                peak = max(length,peak);
            }
        }
        return peak;
    }
};