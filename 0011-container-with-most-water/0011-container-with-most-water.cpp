class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int peak = 0;

        int lowestHeight;
        while(left < right){
            lowestHeight= min(height[left],height[right]);
            peak = max(peak, lowestHeight * (right-left));

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return peak;
    }
};