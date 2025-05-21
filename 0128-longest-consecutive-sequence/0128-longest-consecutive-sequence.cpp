class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> un(s.begin(), s.end());
        int max = 0;
        int count = 0;
        
        int len = un.size();
        if(len == 0){
            return 0;
        }
        for(int i=0;i<len;i++){
            if(i==0){
                
                count +=1;
                continue;
            }

            if(un[i]==un[i-1]+1){
                // cout << un[i] << " " << un[i-1] <<" " << count << endl;
                count+=1;
            }else{
                if(max<count){
                    max = count;
                }
                count = 1;
            }
        }
        if(max<count){
                max = count;
            }
        return max;

    }
};