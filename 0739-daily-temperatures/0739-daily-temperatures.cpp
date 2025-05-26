class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int len = temperatures.size();
        vector<int> ans(len);

        for(int i=len-1; i>=0 ; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }

            ans[i] = st.empty() ? 0 : st.top() - i;

            st.push(i);

        }
        return ans;
    }
};