class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int len = position.size();

        for(int i = 0; i < len; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        vector<float> time;
        for(int i = 0; i < len; i++) {
            time.push_back((double)(target - cars[i].first) / (double)cars[i].second);
        }

        stack<float> st;
        for(int i = len - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= time[i]) {
                st.pop();
            }
            st.push(time[i]);
        }

        return st.size();
    }
};
