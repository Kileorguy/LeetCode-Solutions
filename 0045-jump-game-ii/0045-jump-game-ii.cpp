class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;

        int furthestIdx = -1;
        int selIdx;
        int count = 0;

        int i = 0;
        while(i < size){
            // cout << i << " ==========="<<endl;
            if(i + nums[i] >=size-1){
                count++;
                break;
            }
            if(i == size-1){
                count++;
                break; 
            }

            for(int j=i+1; j<=i+nums[i] && j < size; j++){
                int dist = j + nums[j];
                if(dist >= size-1){
                    selIdx = j;
                    break;
                }
                // cout << j << " " << nums[j] << endl;
                // cout << furthestIdx << " " << dist << endl;
                if(furthestIdx < dist){
                    furthestIdx = dist;
                    selIdx = j;
                }
            }
            i = selIdx;
            count++;
        }
        return count;
    }
};