class Solution {
public:
    int trap(vector<int>& height) {

        int len = height.size();
        int sum = 0;
        for(int i=0; i < len ; i++){
            int area;
            if(i+1 >= len)break;
            while(height[i] < height[i+1]) i++;
            cout << "I : " << i << endl;
            int right = i + 2;

            int max = 0;
            int idx = right;
            if(i >= len || right >= len) break;
            while(right < len-1 && height[i] > height[right]){
                if(max<height[right]){
                    max = height[right];
                    idx = right;
                }
                right++;
            }
            
            if(height[right] > height[idx]){
                idx = right;
            }
            
            area = (idx-i-1) * min(height[i], height[idx]);

            cout << "Right " + to_string(idx) << endl;
            cout << "Area " + to_string(area) << endl;
            for(int j=i+1; j<idx;j++){
                area -= min(height[j], min(height[i], height[idx]));
            }

            cout << "Area " + to_string(area) << endl;

            sum += area;

            i = idx-1;
        }
        return sum;
    }
};