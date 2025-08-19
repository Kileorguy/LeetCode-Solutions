class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> us;
        for(int &n :nums){
            if(us.count(n) == 0){
                us.insert(n);
            }else{
                us.erase(n);
            }
        }
        for ( auto it = us.begin(); it != us.end(); ++it ) return *it;
        return -1;
    }
};