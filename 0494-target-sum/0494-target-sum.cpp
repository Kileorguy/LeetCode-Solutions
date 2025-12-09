class Solution {
public:
    struct pair_hash {
        template<typename T1, typename T2>
        std::size_t operator()(const std::pair<T1,T2>& p) const {
            return std::hash<T1>{}(p.first) ^ (std::hash<T2>{}(p.second) << 1);
        }
    };

    unordered_map<pair<int,int>, int, pair_hash> um;

    int dfs(vector<int> &nums, int target, int idx, int currSum){
        
        if(um.count({idx,currSum})>0){
            return um[{idx,currSum}];
        }

        if(idx < 0){
            if(currSum == target) return 1;
            return 0;
        }

        int positive = dfs(nums, target, idx-1, currSum + nums[idx]);
        int negative = dfs(nums, target, idx-1, currSum - nums[idx]);

        um[{idx, currSum}] = positive+negative; 

        return um[{idx, currSum}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, nums.size()-1, 0);
    }
};