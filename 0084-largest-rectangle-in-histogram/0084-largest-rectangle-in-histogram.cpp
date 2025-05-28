class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int> ps, ns;
        vector<int> prevS(len), nextS(len);
        for(int i=0;i<len;i++){

            while(!ps.empty() && heights[i] <= heights[ps.top()]){
                ps.pop();
            }

            if(ps.empty()) prevS[i] = -1;
            else prevS[i] = ps.top();

            ps.push(i);
        }

        for(int i=len-1; i>=0 ; i--){
            while(!ns.empty() && heights[i] <= heights[ns.top()]){
                ns.pop();
            }
            if(ns.empty()) nextS[i] = len;
            else nextS[i] = ns.top();

            ns.push(i);
        }

        int maxVal = 0;
        for(int i=0;i<len;i++){
            maxVal = max(maxVal,heights[i] * (nextS[i] - prevS[i]- 1));

            // cout << to_string(i) + " " + to_string(nextS[i]) + " " + to_string(prevS[i]) +" " << heights[i] * (nextS[i] - prevS[i] - 1) <<endl;

        }

        

        return maxVal;
    }
};