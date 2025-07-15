class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
            return a.first < b.first; 
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, Compare> pq;

        for (auto& point : points) {
            double dist = point[0]*point[0] + point[1]*point[1];
            if (pq.size() < k) {
                pq.push({dist, move(point)});
            } else if (pq.top().first > dist) {
                pq.pop();
                pq.push({dist, point});
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
