class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int peak = 0;

        while(left < right){
            
            peak = max(peak, min(height[left],height[right]) * (right-left));

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return peak;
    }
};